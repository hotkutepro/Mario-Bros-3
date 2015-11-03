#include "FrkSound.h"

WAVEFORMATEX FrkSound::m_hBufferFormat;
DSBUFFERDESC FrkSound::m_hBufferDescription;
LPDIRECTSOUND8 FrkSound::m_hAudioHandler;
HWND FrkSound::m_hWindowsHandler;

FrkSound::FrkSound(const tchar* audioPath)
{
	LoadAudio(audioPath);
}

FrkSound::~FrkSound(void)
{
	m_hSoundBuffer->Stop();
}

HRESULT FrkSound::InitializeSoundClass(HWND windowsHandler)
{
	m_hWindowsHandler = windowsHandler;

	HRESULT result;
	// Thu tao thiet bi DS
	result = DirectSoundCreate8(0, &m_hAudioHandler, 0);
	result = result | m_hAudioHandler->SetCooperativeLevel(m_hWindowsHandler, DSSCL_PRIORITY);

	ZeroMemory(&m_hBufferFormat, sizeof(WAVEFORMATEX));
	ZeroMemory(&m_hBufferDescription, sizeof(DSBUFFERDESC));

	m_hBufferFormat.wFormatTag = AUDIO_FORMAT_TAG;
	m_hBufferFormat.nChannels = AUDIO_NUM_OF_CHANNEL;
	m_hBufferFormat.nSamplesPerSec = AUDIO_SAMPLE_SPEED;
	m_hBufferFormat.wBitsPerSample = AUDIO_BITS_PER_SAMPLE;
	m_hBufferFormat.nBlockAlign = AUDIO_BLOCK_ALIGN(m_hBufferFormat.wBitsPerSample,
		m_hBufferFormat.nChannels);
	m_hBufferFormat.nAvgBytesPerSec = AUDIO_AVERAGE_BPS(m_hBufferFormat.nSamplesPerSec,
		m_hBufferFormat.nBlockAlign);

	m_hBufferDescription.dwFlags = AUDIO_FLAGS;
	m_hBufferDescription.guid3DAlgorithm = AUDIO_GUID;
	m_hBufferDescription.dwSize = sizeof(DSBUFFERDESC);

	return result;
}

HRESULT FrkSound::ReleaseSoundClass()
{
	if (m_hAudioHandler != 0)
	{
		return m_hAudioHandler->Release();
	}
	return S_OK;
}

HRESULT FrkSound::LoadAudio(const tchar* audioPath)
{
	HRESULT result;
	CWaveFile audioObject;
	result = audioObject.Open(LPTSTR(audioPath), 0, WAVEFILE_READ);

	if (!FAILED(result))
	{
		m_hBufferDescription.dwBufferBytes = audioObject.GetSize();
		m_hBufferDescription.lpwfxFormat = audioObject.m_pwfx;

		result = m_hAudioHandler->CreateSoundBuffer(&m_hBufferDescription, &m_hSoundBuffer, 0);

		VOID* pointerToLockBuffer = 0;
		DWORD lockSize = 0;
		result = result | (m_hSoundBuffer)->Lock(0, AUDIO_BUFFER_SIZE, &pointerToLockBuffer,
			&lockSize, 0, 0, DSBLOCK_ENTIREBUFFER);

		if (!FAILED(result))
		{
			DWORD readedData = 0;
			audioObject.ResetFile();
			result = audioObject.Read((BYTE*)pointerToLockBuffer, lockSize, &readedData);
			if (!FAILED(result))
			{
				(m_hSoundBuffer)->Unlock(pointerToLockBuffer, lockSize, 0, 0);
			}
		}
	}
	audioObject.Close();
	return result;
}

HRESULT FrkSound::Play(bool isLoop, DWORD priority)
{
	return m_hSoundBuffer->Play(0, priority, isLoop & DSBPLAY_LOOPING);
}

HRESULT FrkSound::Stop()
{
	HRESULT result = m_hSoundBuffer->Stop();
	m_hSoundBuffer->SetCurrentPosition(0);
	return result;
}

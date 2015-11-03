#ifndef __SOUND_H__
#define __SOUND_H__

#ifdef _UNICODE
typedef wchar_t tchar;
#else
typedef char tchar;
#endif

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dxguid.lib")

#include <dsound.h>
#include <vector>
#include <memory>

#include "dsutil.h"

#define AUDIO_FORMAT_TAG	 WAVE_FORMAT_ADPCM
#define AUDIO_NUM_OF_CHANNEL	 2
#define AUDIO_SAMPLE_SPEED	 22050
#define AUDIO_BITS_PER_SAMPLE	 16
// 1 tap hop Dword cua flags, ghi ro kha nang cua bo dem.
#define AUDIO_FLAGS	 0
#define AUDIO_BUFFER_SIZE	640000
#define AUDIO_GUID	GUID_NULL

// Can chinh ve cac bytes
#define AUDIO_BLOCK_ALIGN(bitPerSample, nChannels)	(WORD)(bitPerSample / 8 * nChannels)
#define AUDIO_AVERAGE_BPS(samplesPerSec, blockAlign)	(DWORD)(samplesPerSec * blockAlign)


class FrkSound
{
public:
	FrkSound(const tchar* audioPath);
	~FrkSound(void);

	static HRESULT InitializeSoundClass(HWND windowsHandler);
	static HRESULT ReleaseSoundClass();

	HRESULT Play(bool isLoop = false, DWORD priority = 0);
	HRESULT Stop();
private:
	HRESULT LoadAudio(const tchar* audioPath);
private:
	// Dinh dang của bộ đệm trong DS tùy theo âm thanh mà có đinh dạng khác nhau
	static WAVEFORMATEX m_hBufferFormat;
	// Cấu trúc miêu tả bộ đệm thứ cấp ngoài biết được định dạng bộ đêm cần biết vê kích thước của audio và bộ đệm sẽ chứa.
	static DSBUFFERDESC m_hBufferDescription;
	static HWND m_hWindowsHandler;
	// Bien luu tru thiet bi DS
	static LPDIRECTSOUND8 m_hAudioHandler;

	LPDIRECTSOUNDBUFFER m_hSoundBuffer;
};

#endif
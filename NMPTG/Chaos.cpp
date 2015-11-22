#include "Chaos.h"
#include "FrkShareControl.h"

Chaos::Chaos(HINSTANCE hInst, int hW, int hH, char* hName,StateManager* sm) :State(hInst, hW, hH, hName,sm)
{
	
}


Chaos::~Chaos()
{
}

void Chaos::Load()
{					
	qNode = new QNode();
	qNode->LoadQNode("QNode.txt");
	qNode->LoadObjects("Object.txt");
	qNode->InsertObject("OiNode.txt");


	qNode->Connect();
	mushroom = new E_Mushroom(200, 200);
	hero = new Hero();
	hero->Load();
	sw = new SweptAABB();	
	br = new Brick();
	br->Load();
	camera = new FrkCamera(2848, 670);
	map = new Map();
	map->Init("hihi.txt", _LocalContent->LoadTexture("hihi.png"));
	FrkSound* music;
	music->InitializeSoundClass(this->GetwndHandle());
	//music= new FrkSound("E.wav");
	
	//music->Play();

}



void Chaos::Update(float gameTime)
{
	//mario->Update(gameTime);
	mushroom->Update(gameTime);
	mushroom->Load();
	camera->Update(hero->GetPosition());
	hero->Update(gameTime);
	float normalx=0, normaly=0;

	float time=sw->SweptAABB1(hero->getBox(), br->m_hBox, normalx, normaly);
	br->Update(normalx,normaly);
}

void Chaos::Render()
{
	_LocalGraphic->Begin(camera->GetTransformMatrix());		
	map->Render();
	br->Render();
	hero->Render();
	mushroom->Render();
	
	_LocalGraphic->End();
}

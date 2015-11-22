#include "StateManager.h"
#include "State.h"


StateManager::StateManager()
{
	lScene = new list<State*>();
}


StateManager::~StateManager()
{
	
}

void StateManager::Add(State* scene)
{
	lScene->push_front(scene);
}

void StateManager::Remove(State* scene)
{
	lScene->pop_front();
}

void StateManager::Clear()
{
	lScene->clear();
}

void StateManager::Update(float gameTime)
{
	this->m_hCurrentScene = lScene->front();
	this->m_hCurrentScene->Update(gameTime);
}

void StateManager::Render()
{
	this->m_hCurrentScene = lScene->front();
	this->m_hCurrentScene->Render();
}

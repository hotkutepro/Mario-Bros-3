#pragma once
#include <list>

class State;

using namespace std;
class StateManager
{
private:
	list<State*>* lScene;
	State* m_hCurrentScene;
public:
	StateManager();   
	~StateManager();
	static StateManager* Instance;
	static StateManager* GetInstance();
	void Add(State* scene);
	void Remove(State* scene);
	void Clear();
	void Update(float gameTime);
	void Render();
	
};


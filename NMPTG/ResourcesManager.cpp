#include "ResourcesManager.h"
#include <stddef.h>
#include "FrkGraphic.h"
ResourcesManager::ResourcesManager()
{
}


ResourcesManager::~ResourcesManager()
{
}

ResourcesManager* ResourcesManager::Instance = NULL;

ResourcesManager ResourcesManager::GetInstance()
{
	if (Instance == NULL)
	{
		Instance = new ResourcesManager();
	}
	return *Instance;
}

void ResourcesManager::Init(FrkContent* Content)
{
	
}

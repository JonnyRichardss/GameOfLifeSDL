#include "GameOfLifeScene.h"
#include "IncludeGameObjects.h"
GameOfLifeScene::GameOfLifeScene()
{
	name = "Game of life scene";
}

GameOfLifeScene::~GameOfLifeScene()
{
}

void GameOfLifeScene::CreateObjects()
{

	UpdateQueue.push_back(new GameOfLife());
}

void GameOfLifeScene::PreUpdate()
{
}

void GameOfLifeScene::PostUpdate()
{
}

void GameOfLifeScene::Load()
{
}

void GameOfLifeScene::Unload()
{
}

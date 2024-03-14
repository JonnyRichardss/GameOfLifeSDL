#ifndef USE_GAMEOFLIFESCENE
#define USE_GAMEOFLIFESCENE
#include "GameScene.h"
class GameOfLifeScene : public GameScene
{
public:
	GameOfLifeScene();
	~GameOfLifeScene();
	void CreateObjects();
	void PreUpdate();
	void PostUpdate();
	void Load();
	void Unload();
};
#endif // !USE_GAMEOFLIFESCENE



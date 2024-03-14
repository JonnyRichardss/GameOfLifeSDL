#include "GameOfLife.h"

void GameOfLife::Init()
{
	shown = false;
	is_static = true;
	BoundingBox = Vector2(1, 1);
	GoLCell cells[] = { {-1,0},{0,-1},{1,-1},{1,0},{1,1} };
	for (GoLCell g : cells) {
		LiveCells.push_back(g);
	}
}

void GameOfLife::Update()
{
	ClearQueue();
	RunGame();
	EnqueueCells();
}

void GameOfLife::InitVisuals()
{
	//gameoflife has no visuals itself
	SDL_Surface* Surf = ColourRGBA::White().ColouredSurface();
	CellTex = SDL_CreateTextureFromSurface(renderContext, Surf);

	SDL_FreeSurface(Surf);
}

void GameOfLife::RunGame()
{
	std::vector<GoLCell> toCheck;
	std::vector<GoLCell> aliveNext;
	for (GoLCell g : LiveCells) {
		std::vector<GoLCell> neighbours = g.GetNeighbours();
		int numAlive = CheckNeighbours(neighbours);
		if (numAlive == 2 || numAlive == 3)
		{
			aliveNext.push_back(g);
		}
		for (GoLCell neighbour : neighbours)
		{
			auto CheckPos = std::find(toCheck.begin(), toCheck.end(), neighbour);
			auto liveNextPos = std::find(aliveNext.begin(), aliveNext.end(), neighbour);
			if (CheckPos == toCheck.end() && liveNextPos == aliveNext.end())
			{
				toCheck.push_back(neighbour);
			}
		}
		for (GoLCell cell : toCheck)
		{
			if (CheckNeighbours(cell.GetNeighbours()) == 3)
			{
				aliveNext.push_back(cell);
			}
		}
		LiveCells = aliveNext;
	}
}

void GameOfLife::EnqueueCells()
{
	for (GoLCell g : LiveCells) {
		position = Vector2(g.x, g.y);
		SDL_Rect destRect = BBtoDestRect();
		RenderableComponent* r = new RenderableComponent(CellTex, &destRect);
		GolComponents.push_back(r);
	}
	for (RenderableComponent* c : GolComponents) {
		renderer->Enqueue(c);
	}
}

int GameOfLife::CheckNeighbours(std::vector<GoLCell> neighbours)
{
	int output = 0;
	for(GoLCell neighbour : neighbours)
	{
		auto position = std::find(LiveCells.begin(), LiveCells.end(), neighbour);
		if (position != LiveCells.end())
		{
			output++;
		}
	}
	return output;
}

void GameOfLife::ClearQueue()
{
	for (int i = 0; i < GolComponents.size(); i++) {
		delete GolComponents[i];
	}
	GolComponents.clear();
}

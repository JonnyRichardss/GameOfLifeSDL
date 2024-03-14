#ifndef USE_GAMEOFLIFE
#define USE_GAMEOFLIFE
#include "GameObject.h"
struct GoLCell {
	float x, y;
    std::vector<GoLCell> GetNeighbours()
    {
        std::vector<GoLCell> output;
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                if (y == 0 && x == 0)
                {
                    continue;
                }
                output.push_back(GoLCell{ this->x + x, this->y + y });
            }
        }
        return output;
    }
    friend bool operator == (GoLCell lhs, GoLCell rhs) {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }
};
class GameOfLife : public GameObject
{
public:
	//things
	void Init();
protected:

	void Update();
	void InitVisuals();
    void RunGame();
    void EnqueueCells();
    int CheckNeighbours(std::vector<GoLCell> neighbours);
    void ClearQueue();
	std::vector<GoLCell> LiveCells;
    std::vector<RenderableComponent*> GolComponents;
    SDL_Texture* CellTex;
};


#endif // !USE_GAMEOFLIFE

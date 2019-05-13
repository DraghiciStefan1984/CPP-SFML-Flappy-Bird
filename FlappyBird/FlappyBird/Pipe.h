#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"
#include <vector>

using namespace std;
using namespace sf;

class Pipe
{
private:
	GameDataRef _data;
	vector<Sprite> pipeSprites;
	vector<Sprite > pipesToDelete;
	int _landHeight;
	int _pipeSpawnYOffset;

public:
	Pipe(GameDataRef data);

	void SpawnBottomPipe();
	void SpawnTopPipe();
	void SpawnInvisiblePipe();
	void MovePipes(float dt);
	void DrawPipes();
	void RandomisePipeOffset();
	const vector<Sprite> & GetSprites() const;
};
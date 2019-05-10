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

public:
	Pipe(GameDataRef);
	~Pipe();

	void DrawPipes();
};
#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"

using namespace sf;
using namespace std;

class Flash
{
private:
	GameDataRef _data;
	RectangleShape _shape;
	bool _flashOn;

public:
	Flash(GameDataRef data);
	~Flash();

	void Show(float dt);
	void Draw();
};
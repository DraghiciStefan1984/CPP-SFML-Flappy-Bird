#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

class Bird
{
private:
	GameDataRef _data;
	Sprite _birdSprite;

public:
	Bird(GameDataRef data);
	~Bird();

	void Draw();
};
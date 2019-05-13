#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;
using namespace sf;

class HUD
{
private:
	GameDataRef _data;
	Text _scoreText;

public:
	HUD(GameDataRef data);
	~HUD();
	void UpdateScore(int score);
	void Draw();
};
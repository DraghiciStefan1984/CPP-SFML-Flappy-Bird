#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

using namespace sf;
using namespace std;

class Land
{
private:
	GameDataRef _data;
	vector<Sprite>_landSprites;

public:
	Land(GameDataRef data);

	void MoveLand(float dt);
	void DrawLand();
	const vector<Sprite> & GetSprites() const;
};
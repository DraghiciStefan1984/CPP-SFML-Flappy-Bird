#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Flash.h"

using namespace std;
using namespace sf;

class GameState : public State
{
private:
	GameDataRef _data;
	Sprite _background;
	Pipe* pipe;
	Land* land;
	Bird* bird;
	Flash* flash;
	Clock clock;
	Collision collision;
	int _gameState;
	RectangleShape _gameOverFlash;
	bool _flashOn;

public:
	GameState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
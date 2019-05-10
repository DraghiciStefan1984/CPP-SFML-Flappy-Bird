#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"

using namespace std;
using namespace sf;

class GameState : public State
{
private:
	GameDataRef _data;
	Sprite _background;
	Pipe* pipe;

public:
	GameState(GameDataRef data);
	~GameState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
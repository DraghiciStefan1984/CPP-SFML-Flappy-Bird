#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace std;
using namespace sf;

class GameOverState : public State
{
private:
	GameDataRef _data;
	Sprite _background;

public:
	GameOverState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
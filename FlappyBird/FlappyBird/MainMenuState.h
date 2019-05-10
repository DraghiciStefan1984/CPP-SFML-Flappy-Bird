#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace std;
using namespace sf;

class MainMenuState : public State
{
private:
	GameDataRef _data;
	Sprite _background;
	Sprite _title;
	Sprite _playButton;

public:
	MainMenuState(GameDataRef data);
	~MainMenuState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
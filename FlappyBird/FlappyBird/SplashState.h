#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace std;
using namespace sf;

class SplashState: public State
{
private:
	GameDataRef _data;
	Clock _clock;
	Texture _backgroundTexture;
	Sprite _background;

public:
	SplashState(GameDataRef data);
	~SplashState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
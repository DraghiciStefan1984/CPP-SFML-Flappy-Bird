#include "pch.h"
#include "SplashState.h"
#include "DEFINITIONS.h"
#include <iostream>

SplashState::SplashState(GameDataRef data) :_data(data) {}

SplashState::~SplashState() {}

void SplashState::Init()
{
	_data->assetManager.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->assetManager.GetTexture("Splash State Background"));
}

void SplashState::HandleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (Event::Closed == event.type) _data->window.close();
	}
}

void SplashState::Update(float dt) { if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) cout << "main menu" << endl; }

void SplashState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.display();
}
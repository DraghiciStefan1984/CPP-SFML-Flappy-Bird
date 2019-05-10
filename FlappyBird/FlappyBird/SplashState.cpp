#include "pch.h"
#include "SplashState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include <iostream>

SplashState::SplashState(GameDataRef data) : _data(data) {}

SplashState::~SplashState() {}

void SplashState::Init()
{
	this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
}

void SplashState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (Event::Closed == event.type) this->_data->window.close();
	}
}

void SplashState::Update(float dt)
{
	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
}

void SplashState::Draw(float dt)
{
	this->_data->window.clear(Color::Red);
	this->_data->window.draw(this->_background);
	this->_data->window.display();
}
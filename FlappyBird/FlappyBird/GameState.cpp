#include "pch.h"
#include "SplashState.h"
#include "GameState.h"
#include "DEFINITIONS.h"
#include <iostream>

GameState::GameState(GameDataRef data) : _data(data) {}

GameState::~GameState() {}

void GameState::Init()
{
	this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->assets.GetTexture("Game Background"));
}

void GameState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) this->_data->window.close();
	}
}

void GameState::Update(float dt) {}

void GameState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(this->_background);
	this->_data->window.display();
}
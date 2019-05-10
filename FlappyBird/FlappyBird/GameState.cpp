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
	this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
	this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
	pipe = new Pipe(_data);
	_background.setTexture(this->_data->assets.GetTexture("Game Background"));
}

void GameState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) this->_data->window.close();
		if (this->_data->input.IsSpriteClicked(this->_background, Mouse::Left, this->_data->window))
		{

		}
	}
}

void GameState::Update(float dt) 
{
	pipe->MovePipes(dt);
	if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
	{
		pipe->SpawnInvisiblePipe();
		pipe->SpawnBottomPipe();
		pipe->SpawnTopPipe();
		clock.restart();
	}
}

void GameState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(this->_background);
	pipe->DrawPipes();
	this->_data->window.display();
}
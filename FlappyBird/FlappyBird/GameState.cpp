#include "pch.h"
#include "SplashState.h"
#include "GameState.h"
#include "DEFINITIONS.h"
#include <iostream>

GameState::GameState(GameDataRef data) : _data(data) {}

void GameState::Init()
{
	this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
	this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
	this->_data->assets.LoadTexture("Land", LAND_FILEPATH);

	pipe = new Pipe(_data);
	land = new Land(_data);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));
}

void GameState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (Event::Closed == event.type) this->_data->window.close();

		if (this->_data->input.IsSpriteClicked(this->_background, Mouse::Left, this->_data->window))
		{
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();
		}
	}
}

void GameState::Update(float dt)
{
	pipe->MovePipes(dt);
	land->MoveLand(dt);

	if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
	{
		pipe->RandomisePipeOffset();
		pipe->SpawnInvisiblePipe();
		pipe->SpawnBottomPipe();
		pipe->SpawnTopPipe();
		clock.restart();
	}
}

void GameState::Draw(float dt)
{
	this->_data->window.clear(Color::Red);
	this->_data->window.draw(this->_background);
	pipe->DrawPipes();
	land->DrawLand();
	this->_data->window.display();
}
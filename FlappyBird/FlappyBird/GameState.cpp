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
	this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
	this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
	this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
	this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

	pipe = new Pipe(_data);
	land = new Land(_data);
	bird = new Bird(_data);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	_gameState = GameStates::eReady;
}

void GameState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (Event::Closed == event.type) this->_data->window.close();

		if (this->_data->input.IsSpriteClicked(this->_background, Mouse::Left, this->_data->window))
		{
			if (GameStates::eGameOver != _gameState)
			{
				_gameState = GameStates::ePlaying;
				bird->Tap();
			}
		}
	}
}

void GameState::Update(float dt)
{
	if (GameStates::eGameOver != _gameState)
	{
		bird->Animate(dt);
		land->MoveLand(dt);
	}

	if (GameStates::ePlaying == _gameState)
	{
		pipe->MovePipes(dt);

		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
			pipe->RandomisePipeOffset();
			pipe->SpawnInvisiblePipe();
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();
			clock.restart();
		}

		bird->Update(dt);
		vector<Sprite> landSprites = land->GetSprites();

		for (int i = 0; i < landSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision(bird->GetSprite(), landSprites.at(i))) _gameState = GameStates::eGameOver;
		}
	}
}

void GameState::Draw(float dt)
{
	this->_data->window.clear(Color::Red);
	this->_data->window.draw(this->_background);
	pipe->DrawPipes();
	land->DrawLand();
	bird->Draw();
	this->_data->window.display();
}
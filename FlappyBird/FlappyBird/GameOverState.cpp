#include "pch.h"
#include "SplashState.h"
#include "GameOverState.h"
#include "DEFINITIONS.h"
#include "GameState.h"
#include <iostream>

GameOverState::GameOverState(GameDataRef data) : _data(data) {}

void GameOverState::Init()
{
	_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
	_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
	_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
	_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
	_gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Body"));
	_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

	_gameOverContainer.setPosition((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2));
	_gameOverTitle.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height*1.2));
	_retryButton.setPosition((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + (_retryButton.getGlobalBounds().height*0.2));
}

void GameOverState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (Event::Closed == event.type) this->_data->window.close();
		if (_data->input.IsSpriteClicked(_retryButton, Mouse::Left, _data->window)) _data->machine.AddState(StateRef(new GameState(_data)), true);
	}
}

void GameOverState::Update(float dt) {}

void GameOverState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(this->_background);
	this->_data->window.draw(_gameOverContainer);
	this->_data->window.draw(_gameOverTitle);
	this->_data->window.draw(_retryButton);
	this->_data->window.display();
}
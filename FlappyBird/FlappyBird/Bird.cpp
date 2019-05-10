#include "pch.h"
#include "Bird.h"

Bird::Bird(GameDataRef data):_data(data)
{
	_birdSprite.setTexture(_data->assets.GetTexture("Bird Frame 1"));
}

Bird::~Bird()
{
	_data->window.draw(_birdSprite); 
}
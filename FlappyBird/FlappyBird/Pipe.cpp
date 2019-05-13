#include "pch.h"
#include "Pipe.h"
#include "DEFINITIONS.h"

Pipe::Pipe(GameDataRef data) : _data(data)
{
	_landHeight = this->_data->assets.GetTexture("Land").getSize().y;
	_pipeSpawnYOffset = 0;
}

void Pipe::SpawnBottomPipe()
{
	Sprite sprite(this->_data->assets.GetTexture("Pipe Up"));
	sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _pipeSpawnYOffset);
	pipeSprites.push_back(sprite);
}

void Pipe::SpawnTopPipe()
{
	Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));
	sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);
	pipeSprites.push_back(sprite);
}

void Pipe::SpawnInvisiblePipe()
{
	Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));
	sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);
	sprite.setColor(Color(0, 0, 0, 0));
	pipeSprites.push_back(sprite);
}

void Pipe::MovePipes(float dt)
{
	for (int i = 0; i < pipeSprites.size(); i++)
	{
		if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getLocalBounds().width) pipeSprites.erase(pipeSprites.begin() + i);
		else
		{
			Vector2f position = pipeSprites.at(i).getPosition();
			float movement = PIPE_MOVEMENT_SPEED * dt;
			pipeSprites.at(i).move(-movement, 0);
		}
	}
}

void Pipe::DrawPipes() { for (unsigned short int i = 0; i < pipeSprites.size(); i++) this->_data->window.draw(pipeSprites.at(i)); }

void Pipe::RandomisePipeOffset() { _pipeSpawnYOffset = rand() % (_landHeight + 1); }

const vector<Sprite>& Pipe::GetSprites() const { return pipeSprites; }
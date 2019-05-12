#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>

class Bird
{
private:
	GameDataRef _data;
	Sprite _birdSprite;
	vector<Texture> _animationFrames;
	unsigned int _animationIterator;
	Clock _clock;
	Clock _movementClock;
	int _birdState;
	float _rotation;

public:
	Bird(GameDataRef data);
	~Bird();

	void Draw();
	void Animate(float dt);
	void Update(float dt);
	void Tap();
};
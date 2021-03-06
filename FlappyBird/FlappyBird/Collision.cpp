#include "pch.h"
#include "Collision.h"

Collision::Collision() {}

Collision::~Collision() {}

bool Collision::CheckSpriteCollision(Sprite sprite1, Sprite sprite2)
{
	FloatRect rect1 = sprite1.getGlobalBounds();
	FloatRect rect2 = sprite2.getGlobalBounds();

	if (rect1.intersects(rect2)) return true;
	else return false;
}

bool Collision::CheckSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2)
{
	sprite1.setScale(scale1, scale2);
	sprite2.setScale(scale1, scale2);

	FloatRect rect1 = sprite1.getGlobalBounds();
	FloatRect rect2 = sprite2.getGlobalBounds();

	if (rect1.intersects(rect2)) return true;
	else return false;
}

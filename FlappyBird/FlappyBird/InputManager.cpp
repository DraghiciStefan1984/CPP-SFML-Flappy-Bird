#include "pch.h"
#include "InputManager.h"

InputManager::InputManager() {}

InputManager::~InputManager() {}

bool InputManager::IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow &window)
{
	if (Mouse::isButtonPressed(button))
	{
		IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (playButtonRect.contains(sf::Mouse::getPosition(window))) return true;
	}
	return false;
}

Vector2i InputManager::GetMousePosition(RenderWindow &window) { return Mouse::getPosition(window); }
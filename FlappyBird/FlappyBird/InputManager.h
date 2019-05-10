#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class InputManager
{
public:
	InputManager();
	~InputManager();

	bool IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow& window);
	Vector2i GetMousePosition(RenderWindow& window);
};
// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Game.h"
#include "DEFINITIONS.h"

int main()
{
	Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
	return EXIT_SUCCESS;
}
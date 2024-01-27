#ifndef GAME_H

#define GAME_H
#include <iostream>
#include <SDL.h>
#include <SDL_keycode.h>
#include <SDL_ttf.h>


class Game
{
public:
	bool init();
	bool update();
	bool draw();
private:
	SDL_Window* gameWindow;
	SDL_Renderer* gameRenderer;


};

#endif
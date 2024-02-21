#ifndef MTEXTURE_H

#define MTEXTURE_H
//Standard Libs
#include <iostream>
#include <string>
#include <cmath>


//SDL Libs
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class MTexture
{
private:
	//SDL Renderer
	SDL_Renderer* r;
	//The texture this object is wrapping
	SDL_Texture* t;

	//Helper Method that loads a texture from a string path
	SDL_Texture* loadTexture(std::string path);
public:
	MTexture(SDL_Renderer* ren, std::string path);
	MTexture(SDL_Renderer* ren, SDL_Texture* texture);

	SDL_Texture* getTexture();

	void draw();

	void free();
};



#endif
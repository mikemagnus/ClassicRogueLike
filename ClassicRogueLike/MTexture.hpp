#ifndef MTEXTURE_H

#define MTEXTURE_H
//Standard Libs
#include <iostream>

//SDL Libs
#include <SDL.h>
#include <SDL_image.h>

class MTexture
{
private:
	//The texture this object is wrapping
	SDL_Texture* t;
	//The internal rect that will be rendered. Can be used for Sprite Sheets
	SDL_Rect* tRect;
	//The Screen Rect that will be rendered. The destination for whatever is inside the tRect
	SDL_Rect* sRect;
	//Helper Method that loads a texture from a string path
	SDL_Texture* loadTexture(std::string path);
public:
	MTexture(std::string path);
	MTexture(SDL_Texture* texture);
	MTexture(SDL_Texture* texture, SDL_Rect* textureRect, SDL_Rect* screenRect);

	SDL_Texture* getTexture();

	void draw(SDL_Renderer* r);

	void free();
};



#endif
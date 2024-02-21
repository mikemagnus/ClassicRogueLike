#ifndef DRAWABLE_H
#define DRAWABLE_H

//Parent Class
#include "Node.hpp"

class Drawable : public Node 
{
public:
	Drawable(SDL_Renderer* ren);
	Drawable(SDL_Renderer* ren, std::string path);
	~Drawable();

	virtual void draw() = 0;
private:
	//Reference to the main renderer
	SDL_Renderer* r;
	//Reference to the texture this object is drawing
	SDL_Texture* t;

	//Screen Rect where on the screen the drawable will draw
	SDL_Rect sRect;
	//Texture Rect what part of the texture is drawn. NULL for the whole image.
	SDL_Rect tRect;


	//Helper Method for loading textures from file
	SDL_Texture* loadTexture(std::string path);
};

#endif
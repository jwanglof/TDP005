#include "Player.h"

Player::Player()
{
	x = 0;
	y = 0;

	surface = NULL;
	loadSurface("./player.bmp");
}

Player::~Player()
{
	SDL_FreeSurface(surface);
}

void Player::move(SDL_Event *event)
{

	switch (event->type) {
    case SDL_KEYDOWN:
      switch(event->key.keysym.sym){
        case SDLK_LEFT:
          x += -1;
          break;
        case SDLK_RIGHT:
          x += 1;
          break;
        case SDLK_UP:
          y += -1;
          break;
        case SDLK_DOWN:
          y += 1;
          break;
        default:
          break;
       }
       break;
    case SDL_KEYUP:
      switch(event->key.keysym.sym){
        case SDLK_LEFT:
          x += 0;
          break;
        case SDLK_RIGHT:
          x += 0;
          break;
        case SDLK_UP:
          y += 0;
          break;
        case SDLK_DOWN:
          y += 0;
          break;
        default:
          break;
      }
}

	/*
	// Check up-down movement
	if (event->key.keysym.sym == SDLK_w)
		y--;
	else if (event->key.keysym.sym == SDLK_s)
		y++;

	// Check left-right movement
	if (event->key.keysym.sym == SDLK_d)
		x++;
	else if (event->key.keysym.sym == SDLK_a)
		x--; */
}

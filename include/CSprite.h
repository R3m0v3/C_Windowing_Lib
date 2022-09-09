#ifndef CSPRITE_H
#define CSPRITE_H

#include <Cstructs.h>
#include <SDL2/SDL.h>
#include <CWindow.h>

/*
A Sprite Class to handle the load and unload of a sprite. 
In combination with a CSpriteInstance you can render the Sprite on the window.

@param path: path to the sprite sheet
@param rowcollumn: indicates how many rows and collumns the sheet has got.
@param surface: SDL_Surface pointer to the loaded surface.
@param testure: SDL_Texture pointer to the actual texture which can be handled by SDL windows
*/
typedef struct __CSprite{
  char* path;
  RowCollumn rowcollumn;
  SDL_Surface* surface;
  SDL_Texture* texture;
}CSprite;

/*
Constructor for the CSprite Class
@param[in] window: Pointer to the current CWindow
@param[in] path: path to the Sprite sheet
@param[in] rowcollumn: defines how much rows and collumns the sprite sheet has
*/
CSprite* createCSprite(CWindow* window, char* path, RowCollumn rowcollumn);

//Frees the malloced data of the c sprite
void destroyCSprite(CSprite* sprite);

/*
returns the path of the sprite sheet
*/
char* CSpriteGetPath(CSprite* sprite);

/*
returns the row and the collums of the sprite
*/
RowCollumn CSpriteGetRowCollumn(CSprite* sprite);

#endif
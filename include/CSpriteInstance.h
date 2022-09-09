#ifndef CSPRITEINSTANCE_H
#define CSPRITEINSTANCE_H

#include <CSprite.h>
#include <Cenums.h>

/*
A Sprite instance class for handeling the actual rendering on the window. 
Must be combined with a Sprite.

@param sprite: pointer to the sprite which gets used
@param rowCollumn: the current Row and Collumn of the instance in the spritesheet
@param srcRect: source rectangle, decides which frame of the sprite sheet gots taken
@param destRect: destination Rectangle, decides where the Sprite gets rendered on the screen
@param flip: flips the Sprite horizontally and/or vertically
@param rotation: sets the rotation of the sprite in mathematically negative direction
@param rendering: decides if the Sprite gets rendered on the screen or not (1 yes, 0 no)
*/
typedef struct __CSpriteInstance{
  CSprite* sprite;
  RowCollumn rowCollumn;
  SDL_Rect srcRect, destRect;
  SDL_RendererFlip flip;
  double rotation;
  int8_t rendering;
}CSpriteInstance; 

/*
@param[in] sprite: CSprite Pointer of which sprite to Use
@param[in] posdim: Position and Dimension of the Sprite
*/
CSpriteInstance* createCSpriteInstance(CSprite* sprite, PosDim posdim);

//frees the mem space of the instance
void destroyCSpriteInstance(CSpriteInstance* instance);

//returns the Sprite of the CSpriteInstance
CSprite* CSpriteInstanceGetCSprite(CSpriteInstance* spriteInstance);

//sets the Sprite of the CSpriteInstance
void CSpriteInstanceSetCSprite(CSpriteInstance* spriteInstance, CSprite* sprite);

//returns the Position and Dimension of the SpriteInstance on the screen
PosDim CSpriteInstanceGetPosDim(CSpriteInstance* instance);

//sets the Position and Dimension of the Sprite Instance on the Screen
void CSpriteInstanceSetPosDim(CSpriteInstance* instance, PosDim posdim);

//returns the current Row and Collumn of the instance
RowCollumn CSpriteInstanceGetRowCollumn(CSpriteInstance* instance);

//sets the current Row and Collumn of the instance
void CSpriteInstanceSetRowCollumn(CSpriteInstance* instance, RowCollumn rowcollumn);

//returns the current flip of the instance
SDL_RendererFlip CSpriteInstanceGetFlip(CSpriteInstance* instance);

//sets the current flip of the instance
void CSpriteInstanceSetFlip(CSpriteInstance* instance, SDL_RendererFlip flip);

//returns the current Rotation 
double CSpriteInstanceGetRotation(CSpriteInstance* instance);

//sets the current rotation
void CSpriteInstanceSetRotation(CSpriteInstance* instance, double rotation);

//returns 1 if the rendering of the instance is currently active 0 if not
int8_t CSpriteInstanceIsRendering(CSpriteInstance* instance);

//sets the rendering of the instance. 0 false, other true
void CSpriteInstanceSetRendering(CSpriteInstance* instance, int8_t rendering);

//renders the Sprite instance on the window
void CSpriteInstanceRender(CSpriteInstance* instance, CWindow* window);

//goes one step in the sprite sheet in the desired direction
void CSpriteInstanceMakeSpriteStep(CSpriteInstance* instance, Direction dir);

//goes one step right in the sprite sheet
void CSpriteInstanceMakeSpriteStepRight(CSpriteInstance* instance);

//goes one step left in the sprite sheet
void CSpriteInstanceMakeSpriteStepLeft(CSpriteInstance* instance);

//goes one step Up in the sprite sheet
void CSpriteInstanceMakeSpriteStepUp(CSpriteInstance* instance);

//goes one step Down in the sprite sheet
void CSpriteInstanceMakeSpriteStepDown(CSpriteInstance* instance);

#endif
# Chris C Rendering Lib Documentation (Version 1.0)
This is the Documentation to the lib to clarify all sort of things with little examples of usage.

In this doc you may find declarations like "Class" even thought C doesn't suport classes out of the box, but I will use structs in combination with specific functions to act like classes.

Someone may now think - why not use C++ then - it's because of the FFI (foreign function interface) of many other languages which like C way more then C++ Functions. So it will be in C :)

# Version Notes
- Version 1.0:
  - Classes: 
    - Added CWindow
    - Added CSprite
    - Added CSpriteInstance
  - Structs
    - Added PosDim
    - Added RowCollumn
  - Enums
    - Added Direction

# Table of Contents
- [Chris C Rendering Lib Documentation (Version 1.0)](#chris-c-rendering-lib-documentation-version-10)
- [Version Notes](#version-notes)
- [Table of Contents](#table-of-contents)
- [Classes](#classes)
  - [CWindow Class](#cwindow-class)
    - [Definition:](#definition)
    - [Functions:](#functions)
      - [Constructor / Destructor:](#constructor--destructor)
      - [Getter and setter:](#getter-and-setter)
      - [Rendering:](#rendering)
      - [Events](#events)
      - [Other Functions](#other-functions)
  - [CSprite Class](#csprite-class)
    - [Definition:](#definition-1)
    - [Functions:](#functions-1)
      - [Constructor / Destructor:](#constructor--destructor-1)
      - [Getter and Setter:](#getter-and-setter-1)
  - [CSpriteInstance Class](#cspriteinstance-class)
    - [Definition:](#definition-2)
    - [Functions:](#functions-2)
      - [Constructor / Destructor:](#constructor--destructor-2)
      - [Getter and Setter](#getter-and-setter-2)
- [Structs](#structs)
  - [PosDim struct (Position and Dimensions)](#posdim-struct-position-and-dimensions)
    - [Definition:](#definition-3)
    - [Functions:](#functions-3)
  - [RowCollumn struct (Rows and Collumns)](#rowcollumn-struct-rows-and-collumns)
    - [Definition](#definition-4)
    - [Functions:](#functions-4)
- [Enums](#enums)
  - [Direction enum](#direction-enum)
    - [Definition:](#definition-5)

# Classes

## CWindow Class
The CWindow Class. On creation starts a new Cwindow. Manages all Cwindow related stuff, like dimensions, renderer, ... (more following later)

### Definition:
``` C
/*
@param title: current title of the window
@param posdim: set position and dimension of the window on the screen
@param FPS: cuurent max FPS of the window (1/FPS delay with the usage of CWindowDelay(window))
@param sdlwindow: window pointer to the actual SDL_Window
@param sdlrenderer: Pointer to the SDL_Renderer
*/
typedef struct __CWindow{
    char* title;
    PosDim posdim;
    uint16_t FPS;
    SDL_Window* sdlwindow;
    SDL_Renderer* sdlrenderer;
}CWindow;
```

### Functions:

#### Constructor / Destructor:

``` C
/*
Creates a CWindow and returns a pointer to it. Also inits the SDL lib.
@param[in] title: title of the Cwindow
@param[in] posdim: Position and Dimension on the Screen.
@param[in] FPS: FPS on which the Cwindow will be renderered
@param[in] FLAGS: (currently) SDL_WINDOW_FLAGS to e. g. make a Cwindow resizable
*/
CWindow* createCWindow(char* title, PosDim posdim, uint16_t FPS, uint32_t FLAGS);
```
``` C
//Free the mem of the Window and close it.
void destroyCWindow(CWindow* window);
```

#### Getter and setter:

``` C
//returns the title of the Cwindow
char* CWindowGetTitle(CWindow* Cwindow);

//sets the title of the Cwindow
void CWindowSetTitle(CWindow* Cwindow, char* title);
```
``` C
//returns the PosDim struct of the Cwindow
PosDim CWindowGetPosDim(CWindow* Cwindow);

//sets the PosDim of the CWindow (NOT IMPLEMENTED YET)
void CWindowSetPosDim(CWindow* Cwindow, PosDim posdim);
```
``` C
//returns the current MAX FPS of the Cwindow
uint16_t CWindowGetFPS(CWindow* Cwindow);

//sets the current MAX FPS of the Cwindow
void CWindowSetFPS(CWindow* Cwindow, uint16_t maxFPS);
```
```C
//returns the SDL_Window pointer of the Cwindow
SDL_Window* CWindowGetSDLWindow(CWindow* Cwindow);

//returns the SDL_Renderer pointer of the Cwindow
SDL_Renderer* CWindowGetSDLRenderer(CWindow* Cwindow);
```

#### Rendering:

```C
//polls the Events from the SDL Event Queue
void CWindowPollEvents(CWindow* Cwindow);
```
```C
//Clears the screen in the start of every rendering sequence
void CWindowClearScreen(CWindow* Cwindow);
```
```C
//Shows the current rendered objects on screen
void CWindowShowRendered(CWindow* Cwindow);
```

#### Events

```C
/*
checks if the given key is pressed and returns 1 if true and 0 if false
@param keyCode: SDL_Scancode of the Key to be checked
*/
int8_t CWindowIsKeyPressed(CWindow* Cwindow, SDL_Scancode keyCode);
```

#### Other Functions

```C
//pauses the Thread for Delay milliseconds
void CDelay(uint16_t Delay);

//pauses the Thread for 1/FPS seconds
void CWindowDelay(CWindow* window);
```
<br>

## CSprite Class

A Sprite Class to handle the load and unload of a sprite. In combination with a CSpriteInstance you can render the Sprite on the window.

### Definition:

```C
/*
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
```

### Functions:

#### Constructor / Destructor:
```C
/*
Constructor for the CSprite Class
@param[in] window: Pointer to the current CWindow
@param[in] path: path to the Sprite sheet
@param[in] rowcollumn: defines how much rows and collumns the sprite sheet has
*/
CSprite* createCSprite(CWindow* window, char* path, RowCollumn rowcollumn);
```
```C
//Frees the malloced data of the c sprite
void destroyCSprite(CSprite* sprite);
```

#### Getter and Setter:

``` C
/*
returns the path of the sprite sheet
*/
char* CSpriteGetPath(CSprite* sprite);
```
```C
/*
returns the row and the collums of the sprite
*/
RowCollumn CSpriteGetRowCollumn(CSprite* sprite);
```

## CSpriteInstance Class

A Sprite instance class for handeling the actual rendering on the window. Must be combined with a Sprite.

### Definition:
```C
/*
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
```

### Functions:

#### Constructor / Destructor:

```C
/*
@param[in] sprite: CSprite Pointer of which sprite to Use
@param[in] posdim: Position and Dimension of the Sprite
*/
CSpriteInstance* createCSpriteInstance(CSprite* sprite, PosDim posdim);
```
```C
//frees the mem space of the instance
void destroyCSpriteInstance(CSpriteInstance* instance);
```

#### Getter and Setter

```C
//returns the Sprite of the CSpriteInstance
CSprite* CSpriteInstanceGetCSprite(CSpriteInstance* spriteInstance);

//sets the Sprite of the CSpriteInstance
void CSpriteInstanceSetCSprite(CSpriteInstance* spriteInstance, CSprite* sprite);
```
```C
//returns the Position and Dimension of the SpriteInstance on the screen
PosDim CSpriteInstanceGetPosDim(CSpriteInstance* instance);

//sets the Position and Dimension of the Sprite Instance on the Screen
void CSpriteInstanceSetPosDim(CSpriteInstance* instance, PosDim posdim);
```
```C
//returns the current Row and Collumn of the instance
RowCollumn CSpriteInstanceGetRowCollumn(CSpriteInstance* instance);

//sets the current Row and Collumn of the instance
void CSpriteInstanceSetRowCollumn(CSpriteInstance* instance, RowCollumn rowcollumn);
```
```C
//returns the current flip of the instance
SDL_RendererFlip CSpriteInstanceGetFlip(CSpriteInstance* instance);

//sets the current flip of the instance
void CSpriteInstanceSetFlip(CSpriteInstance* instance, SDL_RendererFlip flip);
```
```C
//returns the current Rotation 
double CSpriteInstanceGetRotation(CSpriteInstance* instance);

//sets the current rotation
void CSpriteInstanceSetRotation(CSpriteInstance* instance, double rotation);
```
```C
//returns 1 if the rendering of the instance is currently active 0 if not
int8_t CSpriteInstanceIsRendering(CSpriteInstance* instance);

//sets the rendering of the instance. 0 false, other true
void CSpriteInstanceSetRendering(CSpriteInstance* instance, int8_t rendering);
```
```C
//renders the Sprite instance on the window
void CSpriteInstanceRender(CSpriteInstance* instance, CWindow* window);
```
```C
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
```

# Structs

## PosDim struct (Position and Dimensions)
### Definition:
``` C
typedef struct __PosDim{
    int32_t x, y;
    uint32_t w, h;
}PosDim;
```

### Functions:
``` C
/*
Returns a PosDim struct with the given parameters or NULL if it failes
@param x: x coordinate on screen
@param y: y coordinate on screen
@param w: current width
@param h: current height
*/
PosDim createPosDim(int32_t x, int32_t y, uint32_t w, uint32_t h);
```

## RowCollumn struct (Rows and Collumns)
### Definition

``` C
typedef struct __RowCollumn{
  uint32_t r, c;
}RowCollumn;
```
### Functions:
```C
/*
Returns a RowCollumn struct with the given parameters
@param uint32_t rows: count of rows in this struct
@param uint32_t collumns: count of collumns in this struct
*/
RowCollumn createRowCollumn(uint32_t rows, uint32_t collumns);
```

# Enums

## Direction enum
### Definition:
```C
typedef enum __Direction{
  up,
  upRighleft,
  downRight,
  down,
  downLeft,
  left,
  upLeft,
}Direction;
```
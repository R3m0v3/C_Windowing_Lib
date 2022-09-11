#ifndef CWINDOW_H
#define CWINDOW_H

#ifdef _WIN32
//#define __WIN32__
#endif

#include <SDL2/SDL.h>

#include <Cstructs.h>

/*
The CWindow Class. On creation starts a new Cwindow. 
Manages all Cwindow related stuff,
like dimensions, renderer, ... (more following later)

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

/*
Creates a CWindow and returns a pointer to it. Also inits the SDL lib.
@param[in] title: title of the Cwindow
@param[in] posdim: Position and Dimension on the Screen.
@param[in] FPS: FPS on which the Cwindow will be renderered
@param[in] FLAGS: (currently) SDL_WINDOW_FLAGS to e. g. make a Cwindow resizable
*/
CWindow* createCWindow(char* title, PosDim posdim, uint16_t FPS, uint32_t FLAGS);

//Free the mem of the Window and close it.
void destroyCWindow(CWindow* window);

//returns the title of the Cwindow
char* CWindowGetTitle(CWindow* Cwindow);

//sets the title of the Cwindow
void CWindowSetTitle(CWindow* Cwindow, char* title);

//returns the PosDim struct of the Cwindow
PosDim CWindowGetPosDim(CWindow* Cwindow);

//sets the PosDim of the CWindow (NOT IMPLEMENTED YET)
void CWindowSetPosDim(CWindow* Cwindow, PosDim posdim);

//returns the current MAX FPS of the Cwindow
uint16_t CWindowGetFPS(CWindow* Cwindow);

//sets the current MAX FPS of the Cwindow
void CWindowSetFPS(CWindow* Cwindow, uint16_t maxFPS);

//returns the SDL_Window pointer of the Cwindow
SDL_Window* CWindowGetSDLWindow(CWindow* Cwindow);

//returns the SDL_Renderer pointer of the Cwindow
SDL_Renderer* CWindowGetSDLRenderer(CWindow* Cwindow);

//polls the Events from the SDL Event Queue
void CWindowPollEvents(CWindow* Cwindow);

//Clears the screen in the start of every rendering sequence
void CWindowClearScreen(CWindow* Cwindow);

//Shows the current rendered objects on screen
void CWindowShowRendered(CWindow* Cwindow);

/*
checks if the given key is pressed and returns 1 if true and 0 if false
@param keyCode: SDL_Scancode of the Key to be checked
*/
int8_t CWindowIsKeyPressed(CWindow* Cwindow, SDL_Scancode keyCode);

//pauses the Thread for Delay milliseconds
void CDelay(uint16_t Delay);

//pauses the Thread for 1/FPS seconds
void CWindowDelay(CWindow* window);

#endif
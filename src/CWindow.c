#include <CWindow.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

#define MAX_CWINDOW_TITLE_LEN 1000

CWindow* createCWindow(char* title, PosDim posdim, uint16_t FPS, uint32_t FLAGS){
    CWindow* cwin;
    if((cwin = (CWindow*) malloc(sizeof(CWindow))) == NULL){
        fprintf(stderr, "Creation Failed!");
        return NULL;
    }

    int counter = 0;
    while(counter < MAX_CWINDOW_TITLE_LEN && title[counter] != '\0'){
        counter++;
    }
    counter++;

    cwin->title = (char*)malloc(counter*sizeof(char));
    strncpy(cwin->title, title, counter);

    cwin->posdim = createPosDim(posdim.x, posdim.y, posdim.w, posdim.h);
    cwin->FPS = FPS;

    if(SDL_Init(SDL_INIT_EVERYTHING)){
        fprintf(stderr, "SDL Failed to INIT!");
    }

    if(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG) == 0){
        fprintf(stderr, "SDL IMG LOAD ERROR!!!");
    }

    cwin->sdlwindow = SDL_CreateWindow(cwin->title, posdim.x, posdim.y, posdim.w, posdim.h, FLAGS);
    cwin->sdlrenderer = SDL_CreateRenderer(cwin->sdlwindow, -1, 0);

    return cwin;
}

void destroyCWindow(CWindow* window){
    free(window->title);
    SDL_DestroyRenderer(window->sdlrenderer);
    SDL_DestroyWindow(window->sdlwindow);
    free(window);
}


char* CWindowGetTitle(CWindow* Cwindow){
    return Cwindow->title;
}

void CWindowSetTitle(CWindow* Cwindow, char* title){
    free(Cwindow->title);
    
    int counter = 0;
    while(counter < MAX_CWINDOW_TITLE_LEN && title[counter] != '\0'){
        counter++;
    }
    counter++;

    Cwindow->title = (char*)malloc(counter*sizeof(char));
    strncpy(Cwindow->title, title, counter);

    SDL_SetWindowTitle(Cwindow->sdlwindow, Cwindow->title);
}


PosDim CWindowGetPosDim(CWindow* Cwindow){
    return Cwindow->posdim;
}

void CWindowSetPosDim(CWindow* Cwindow, PosDim posdim){
    Cwindow->posdim.x = posdim.x;
    Cwindow->posdim.y = posdim.y;
    Cwindow->posdim.h = posdim.h;
    Cwindow->posdim.w = posdim.w;
    
    SDL_SetWindowPosition(Cwindow->sdlwindow, posdim.x, posdim.y);
    SDL_SetWindowSize(Cwindow->sdlwindow, posdim.w, posdim.h);
}


uint16_t CWindowGetFPS(CWindow* Cwindow){
    return Cwindow->FPS;
}

void CWindowSetFPS(CWindow* Cwindow, uint16_t maxFPS){
    Cwindow->FPS = maxFPS;
}


SDL_Window* CWindowGetSDLWindow(CWindow* Cwindow){
    return Cwindow->sdlwindow;
}

SDL_Renderer* CWindowGetSDLRenderer(CWindow* Cwindow){
    return Cwindow->sdlrenderer;
}

void CWindowPollEvents(CWindow* Cwindow){
    SDL_PollEvent(NULL);
}

void CWindowClearScreen(CWindow* Cwindow){
    SDL_SetRenderDrawColor(Cwindow->sdlrenderer, 0, 0, 0, 255);
    SDL_RenderClear(Cwindow->sdlrenderer);
}

void CWindowShowRendered(CWindow* Cwindow){
    SDL_RenderPresent(Cwindow->sdlrenderer);
}

int8_t CWindowIsKeyPressed(CWindow* Cwindow, SDL_Scancode keyCode){
    SDL_PumpEvents();
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if(state[keyCode]){
        return 1;
    }
    return 0;
}

void CDelay(uint16_t Delay){
    SDL_Delay(Delay);
}
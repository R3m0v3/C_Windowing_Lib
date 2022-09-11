#include <CSprite.h>
#include <SDL2/SDL_image.h>
#include <string.h>

CSprite* createCSprite(CWindow* window, char* path, RowCollumn rowcollumn){
    CSprite* sprite = (CSprite*)malloc(sizeof(CSprite));

    sprite->path = (char*)malloc((strlen(path)+1)*sizeof(char));
    strncpy(sprite->path, path, strlen(path)+1);

    sprite->rowcollumn.c = rowcollumn.c; 
    sprite->rowcollumn.r = rowcollumn.r;

    sprite->surface = IMG_Load(path);
    sprite->texture = SDL_CreateTextureFromSurface(window->sdlrenderer, sprite->surface);
    return sprite;
}

void destroyCSprite(CSprite* sprite){
    free(sprite->path);
    SDL_FreeSurface(sprite->surface);
    SDL_DestroyTexture(sprite->texture);
    free(sprite);
}

char* CSpriteGetPath(CSprite* sprite){
    return sprite->path;
}

RowCollumn CSpriteGetRowCollumn(CSprite* sprite){
    RowCollumn tmp;
    tmp.c = sprite->rowcollumn.c;
    tmp.r = sprite->rowcollumn.r;
    return tmp;
}
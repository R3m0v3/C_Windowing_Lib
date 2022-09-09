#include <CSpriteInstance.h>

CSpriteInstance* createCSpriteInstance(CSprite* sprite, PosDim posdim){
    CSpriteInstance* instance = (CSpriteInstance*)malloc(sizeof(CSpriteInstance));
    instance->sprite = sprite;

    instance->rowCollumn.r = 0;
    instance->rowCollumn.c = 0;

    instance->srcRect.w = instance->sprite->surface->w/instance->sprite->rowcollumn.c;
    instance->srcRect.h = instance->sprite->surface->h/instance->sprite->rowcollumn.r;
    instance->srcRect.x = 0;
    instance->srcRect.y = 0;//instance->sprite->surface->h-instance->srcRect.h;

    instance->destRect.x = posdim.x; 
    instance->destRect.y = posdim.y;
    instance->destRect.w = posdim.w;
    instance->destRect.h = posdim.h;

    instance->flip = SDL_FLIP_NONE;

    instance->rotation = 0.0;

    instance->rendering = 1;
}

void destroyCSpriteInstance(CSpriteInstance* instance){
    free(instance);
}

CSprite* CSpriteInstanceGetCSprite(CSpriteInstance* spriteInstance){
    return spriteInstance->sprite;
}

void CSpriteInstanceSetCSprite(CSpriteInstance* spriteInstance, CSprite* sprite){
    spriteInstance->sprite = sprite;
}

PosDim CSpriteInstanceGetPosDim(CSpriteInstance* instance){
    PosDim posdim;
    posdim.x = instance->destRect.x;
    posdim.y = instance->destRect.y;
    posdim.w = instance->destRect.w;
    posdim.h = instance->destRect.h;
    return posdim;
}

void CSpriteInstanceSetPosDim(CSpriteInstance* instance, PosDim posdim){
    instance->destRect.x = posdim.x;
    instance->destRect.y = posdim.y;
    instance->destRect.w = posdim.w;
    instance->destRect.h = posdim.h;
}

RowCollumn CSpriteInstanceGetRowCollumn(CSpriteInstance* instance){
    return instance->sprite->rowcollumn;
}

void CSpriteInstanceSetRowCollumn(CSpriteInstance* instance, RowCollumn rowcollumn){
    instance->rowCollumn.c = rowcollumn.c;
    instance->rowCollumn.r = rowcollumn.r;

    instance->srcRect.x = instance->srcRect.w * rowcollumn.c;
    instance->srcRect.y = instance->srcRect.h * rowcollumn.r;
}

SDL_RendererFlip CSpriteInstanceGetFlip(CSpriteInstance* instance){
    return instance->flip;
}

void CSpriteInstanceSetFlip(CSpriteInstance* instance, SDL_RendererFlip flip){
    instance->flip = flip;
}

double CSpriteInstanceGetRotation(CSpriteInstance* instance){
    return instance->rotation;
}

void CSpriteInstanceSetRotation(CSpriteInstance* instance, double rotation){
    instance->rotation = rotation;
}

int8_t CSpriteInstanceIsRendering(CSpriteInstance* instance){
    return instance->rendering;
}

void CSpriteInstanceSetRendering(CSpriteInstance* instance, int8_t rendering){
    if(rendering == 0)
        instance->rendering = 0;
    else
        instance->rendering = 1;
}

void CSpriteInstanceRender(CSpriteInstance* instance, CWindow* window){
    if(instance->rendering == 1)
        SDL_RenderCopyEx(window->sdlrenderer, instance->sprite->texture, &instance->srcRect, &instance->destRect, instance->rotation, NULL, instance->flip);
}

void CSpriteInstanceMakeSpriteStep(CSpriteInstance* instance, Direction dir){
    switch(dir){
        case up:        CSpriteInstanceMakeSpriteStepUp(instance); break;
        case upRight:   CSpriteInstanceMakeSpriteStepUp(instance); CSpriteInstanceMakeSpriteStepRight(instance); break;
        case right:     CSpriteInstanceMakeSpriteStepRight(instance); break;
        case downRight: CSpriteInstanceMakeSpriteStepDown(instance); CSpriteInstanceMakeSpriteStepRight(instance); break;
        case down:      CSpriteInstanceMakeSpriteStepDown(instance); break;
        case downLeft:  CSpriteInstanceMakeSpriteStepDown(instance); CSpriteInstanceMakeSpriteStepLeft(instance); break;
        case left:      CSpriteInstanceMakeSpriteStepLeft(instance); break;
        case upLeft:    CSpriteInstanceMakeSpriteStepUp(instance); CSpriteInstanceMakeSpriteStepLeft(instance); break;
    }
}

void CSpriteInstanceMakeSpriteStepRight(CSpriteInstance* instance){
    if(instance->srcRect.x >= instance->sprite->surface->w-instance->srcRect.w){
        instance->srcRect.x = 0;
        instance->rowCollumn.c = 0;
    }
    else{ 
        instance->srcRect.x += instance->srcRect.w;
        instance->rowCollumn.c += 1;
    }
}

void CSpriteInstanceMakeSpriteStepLeft(CSpriteInstance* instance){
    if(instance->srcRect.x <= 0){
        instance->srcRect.x = instance->sprite->surface->w-instance->srcRect.w;
        instance->rowCollumn.c = instance->sprite->rowcollumn.c;
    }
    else{
        instance->srcRect.x -= instance->srcRect.w;
        instance->rowCollumn.c -= 1;
    }
}

void CSpriteInstanceMakeSpriteStepUp(CSpriteInstance* instance){
    if(instance->srcRect.y <= 0){
        instance->srcRect.y = instance->sprite->surface->h-instance->srcRect.h;
        instance->rowCollumn.r = instance->sprite->rowcollumn.r;
    }
    else{
        instance->srcRect.y -= instance->srcRect.h;
        instance->rowCollumn.r -= 1;
    }
}

void CSpriteInstanceMakeSpriteStepDown(CSpriteInstance* instance){
    if(instance->srcRect.y >= instance->sprite->surface->h-instance->srcRect.h){
        instance->srcRect.y = 0;
        instance->rowCollumn.r = 0;
    }
    else{
        instance->srcRect.y += instance->srcRect.h;
        instance->rowCollumn.r += 1;
    }
}
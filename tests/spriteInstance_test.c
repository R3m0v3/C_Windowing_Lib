#include <CWindow.h>
#include <CSpriteInstance.h>

//create A SpriteInstance and render it on screen
void test1(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CSprite* sprite = createCSprite(window, "../tests/test_sprites/pic.png", createRowCollumn(4, 4));

    CSpriteInstance* instance = createCSpriteInstance(sprite, createPosDim(100, 100, 100, 100));

    CSpriteInstanceRender(instance, window);

    CWindowShowRendered(window);
    CDelay(2000);

    destroyCSpriteInstance(instance);
    destroyCSprite(sprite);
    destroyCWindow(window);
}

//test of PosDim setter and getter
void test2(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CSprite* sprite = createCSprite(window, "../tests/test_sprites/pic.png", createRowCollumn(4, 4));

    CSpriteInstance* instance = createCSpriteInstance(sprite, createPosDim(100, 100, 100, 100));

    CSpriteInstanceRender(instance, window);

    CWindowShowRendered(window);
    CDelay(2000);

    for(int i = 0; i<500; i++){
        CWindowClearScreen(window);

        PosDim currentPosDim = CSpriteInstanceGetPosDim(instance);
        currentPosDim.x += 1;
        currentPosDim.y += 1;
        CSpriteInstanceSetPosDim(instance, currentPosDim);

        CSpriteInstanceRender(instance, window);
        CWindowShowRendered(window);
        CDelay(16);
    }

    destroyCSpriteInstance(instance);
    destroyCSprite(sprite);
    destroyCWindow(window);
}

//test of get and set flip
void test3(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CSprite* sprite = createCSprite(window, "../tests/test_sprites/pic.png", createRowCollumn(4, 4));

    CSpriteInstance* instance = createCSpriteInstance(sprite, createPosDim(100, 100, 100, 100));

    CSpriteInstanceRender(instance, window);

    CWindowShowRendered(window);
    CDelay(2000);

    CWindowClearScreen(window);
    CSpriteInstanceSetFlip(instance, SDL_FLIP_VERTICAL);
    CSpriteInstanceRender(instance, window);
    CWindowShowRendered(window);
    CDelay(2000);

    destroyCSpriteInstance(instance);
    destroyCSprite(sprite);
    destroyCWindow(window);
}

//tests rotation
void test4(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CSprite* sprite = createCSprite(window, "../tests/test_sprites/pic.png", createRowCollumn(4, 4));

    CSpriteInstance* instance = createCSpriteInstance(sprite, createPosDim(100, 100, 100, 100));

    CSpriteInstanceRender(instance, window);

    CWindowShowRendered(window);
    CDelay(2000);

    for(int i = 0; i<500; i++){
        CWindowClearScreen(window);

        CSpriteInstanceSetRotation(instance, CSpriteInstanceGetRotation(instance)+2.0);

        CSpriteInstanceRender(instance, window);
        CWindowShowRendered(window);
        CDelay(16);
    }

    destroyCSpriteInstance(instance);
    destroyCSprite(sprite);
    destroyCWindow(window);
}

//test of the sprite step functions
void test5(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CSprite* sprite = createCSprite(window, "../tests/test_sprites/pic.png", createRowCollumn(4, 4));

    CSpriteInstance* instance = createCSpriteInstance(sprite, createPosDim(100, 100, 100, 100));

    CSpriteInstanceRender(instance, window);

    CWindowShowRendered(window);
    CDelay(2000);

    for(int i = 0; i<20; i++){
        CWindowClearScreen(window);

        CSpriteInstanceMakeSpriteStepRight(instance);

        CSpriteInstanceRender(instance, window);
        CWindowShowRendered(window);
        CDelay(500);
    }
    for(int i = 0; i<20; i++){
        CWindowClearScreen(window);

        CSpriteInstanceMakeSpriteStepLeft(instance);

        CSpriteInstanceRender(instance, window);
        CWindowShowRendered(window);
        CDelay(500);
    }
    for(int i = 0; i<20; i++){
        CWindowClearScreen(window);

        CSpriteInstanceMakeSpriteStepDown(instance);

        CSpriteInstanceRender(instance, window);
        CWindowShowRendered(window);
        CDelay(500);
    }
    for(int i = 0; i<20; i++){
        CWindowClearScreen(window);

        CSpriteInstanceMakeSpriteStepUp(instance);

        CSpriteInstanceRender(instance, window);
        CWindowShowRendered(window);
        CDelay(500);
    }


    CWindowClearScreen(window);

    CSpriteInstanceSetRowCollumn(instance, createRowCollumn(0, 0));

    CSpriteInstanceRender(instance, window);
    CWindowShowRendered(window);
    CDelay(500);

    CWindowClearScreen(window);

    CSpriteInstanceSetRowCollumn(instance, createRowCollumn(0, 3));

    CSpriteInstanceRender(instance, window);
    CWindowShowRendered(window);
    CDelay(500);

    destroyCSpriteInstance(instance);
    destroyCSprite(sprite);
    destroyCWindow(window);
}



int main(int argc, char const *argv[]){
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

#include <CWindow.h>
#include <CSprite.h>

#include <stdio.h>

//Complete test for the CSprite Class
void test1(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CSprite* sprite = createCSprite(window, "../tests/test_sprites/pic.png", createRowCollumn(4, 4));
    printf("%s\n", CSpriteGetPath(sprite));
    printf("rows = %d , collumns = %d \n", CSpriteGetRowCollumn(sprite).r, CSpriteGetRowCollumn(sprite).c);
    destroyCSprite(sprite);

    destroyCWindow(window);
}

int main(int argc, char const *argv[]){
    test1();
}

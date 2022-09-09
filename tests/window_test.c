#include <CWindow.h>

#include <stdio.h>

/*
Creates a window and and waits for one sec
*/
void test1(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);
    destroyCWindow(window);
}

//Test Set and get Title
void test2(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CWindowSetTitle(window, "Hallo Moerch!");
    printf("%s\n", CWindowGetTitle(window));
    CDelay(2000);
    destroyCWindow(window);
}

//test get and set PosDim
void test3(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CWindowSetPosDim(window, createPosDim(100, 100, 500, 500));
    PosDim currentWindowPos = CWindowGetPosDim(window);
    printf("x = %d , y = %d , w = %d , h = %d \n", currentWindowPos.x, currentWindowPos.y, currentWindowPos.w, currentWindowPos.h);
    CDelay(2000);
    destroyCWindow(window);
}

//test get set FPS
void test4(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CWindowSetFPS(window, 100);
    printf("%d\n", CWindowGetFPS(window));
    destroyCWindow(window);
}

//test Poll Events and Key Pressed
void test5(){
    CWindow* window = createCWindow("Hallo Sneis", createPosDim(0, 0, 1000, 600), 60, 0);
    CWindowClearScreen(window);
    CWindowShowRendered(window);
    CDelay(1000);

    CWindowPollEvents(window);
    printf("Press ESC to continue!\n");
    while(!CWindowIsKeyPressed(window, SDL_SCANCODE_ESCAPE));
    destroyCWindow(window);
}

int main(int argc, char const *argv[]){
   test1();
   test2();
   test3();
   test4();
   test5();
   printf("\x1b[32m" "THE WINDOW CLASS WORKS!!!" "\x1b[0m" "\n");
}





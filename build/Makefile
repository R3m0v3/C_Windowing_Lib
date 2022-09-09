CC = gcc
CFLAGS = ~/Dokumente/Tutorials/SDL/SDL/build/build/.libs/libSDL2.a ~/Dokumente/Tutorials/SDL/SDL/build/build/.libs/libSDL2main.a ~/Dokumente/Tutorials/SDL/libSDL2_image.a -ldl -lpthread -lm
INC = -I../include/
SRC = ../src/*.c


#TESTS
window_test_run:
	@$(CC) -g -o window_test ../tests/window_test.c $(SRC) $(INC) $(CFLAGS)
	@./window_test
	@rm window_test

sprite_test_run:
	@$(CC) -g -o sprite_test ../tests/sprite_test.c $(SRC) $(INC) $(CFLAGS)
	@./sprite_test
	@rm sprite_test

sprite_instance_test_run:
	@$(CC) -g -o sprite_instance_test ../tests/spriteInstance_test.c $(SRC) $(INC) $(CFLAGS)
	@./sprite_instance_test
	@rm sprite_instance_test

CC = gcc
CC_WINDOWS = x86_64-w64-mingw32-gcc

CFLAGS = ~/Dokumente/Projekte/Libs/Linux/libSDL2.a ~/Dokumente/Projekte/Libs/Linux/libSDL2main.a ~/Dokumente/Projekte/Libs/Linux/libSDL2_image.a -ldl -lpthread -lm
CFLAGS_WINDOWS = ~/Dokumente/Projekte/Libs/Windows/x86_mingw/libSDL2main.a ~/Dokumente/Projekte/Libs/Windows/x86_mingw/libSDL2.a  ~/Dokumente/Projekte/Libs/Windows/x86_mingw/libSDL2_image.a -lpsapi -m64

INC = -I../include/
INC_WINDOWS = -I ../include/ -I ~/Dokumente/Projekte/Libs/

SRC = ../src/*.c


#Make Library
create_C_rendering_lib:
	@$(CC) -c $(SRC) $(INC)
	@ar -x ~/Dokumente/Tutorials/SDL/SDL/build/build/.libs/libSDL2.a  
	@ar -x ~/Dokumente/Tutorials/SDL/SDL/build/build/.libs/libSDL2main.a
	@ar -x ~/Dokumente/Tutorials/SDL/libSDL2_image.a
	@ar -rc libC_Rendering.a *.o
	@rm *.o

#Make Rust lib
create_Rust_rendering_lib: create_C_rendering_lib
	@rustc -l static=C_Rendering -L. ../bindings/rust-c_Rendering_Lib.rs

#Clean the Libs
clean_libs:
	@rm rust-c_Rendering_Lib libC_Rendering.a

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

sprite_instance_test_run_windows:
	@$(CC_WINDOWS) -o sprite_instance_test.exe ../tests/spriteInstance_test.c $(INC_WINDOWS) $(SRC) $(CFLAGS_WINDOWS) -lws2_32

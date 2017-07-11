#OBJS specifies which files to compile as part of the project
OBJS = ./spike/sdl_test.cpp

#cc specifies the compiler in use
CC = g++

#COMPILER_FLAGS specifies any additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking to
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of our executable
OBJ_NAME = sdl_test

#This is the target that compiles our executable
default :
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

#OBJS specifies which files to compile as part of the project
OBJS = ./src/main.cpp ./src/GameHandler.cpp ./src/LinkedList.cpp ./src/PlatformVector.cpp ./src/Player.cpp ./src/Terrain.cpp ./src/TerrainVector.cpp ./src/Vector2.cpp

#cc specifies the compiler in use
CC = g++

#COMPILER_FLAGS specifies any additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking to
LINKER_FLAGS =

#OBJ_NAME specifies the name of our executable
OBJ_NAME = ./bin/lunar_lander

#This is the target that compiles our executable
default :
	mkdir bin
	mkdir build
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean:
	\rm -f -r -v bin build

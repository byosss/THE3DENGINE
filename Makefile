CC = g++
CFLAGS = -Iinclude
LIBS = -Llib -lglfw3 -lopengl32 -lgdi32

SRC_DIR = src
OBJ_DIR = bin

SRC_CPP = $(wildcard $(SRC_DIR)/*.cpp)
SRC_C = $(wildcard $(SRC_DIR)/*.c)

OBJ_CPP = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_CPP))
OBJ_C = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_C))

TARGET = projet

all : mrproper run

run : build exe

build : $(OBJ_DIR)/$(TARGET)

$(OBJ_DIR)/$(TARGET): $(OBJ_CPP) $(OBJ_C)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)


clean :
	del /Q $(OBJ_DIR)\*.o

mrproper : clean
	del /Q $(OBJ_DIR)\$(TARGET).exe

exe : $(OBJ_DIR)/$(TARGET)
	$(OBJ_DIR)/$(TARGET).exe
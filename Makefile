CC = g++
CFLAGS = -Iinclude
LIBS = -Llib -lglfw3 -lopengl32 -lgdi32

SRC_DIR = src
OBJ_DIR = bin

SRC_CPP = $(wildcard $(SRC_DIR)/*.cpp)
SRC_CPP += $(wildcard $(SRC_DIR)/*/*.cpp)
SRC_CPP += $(wildcard $(SRC_DIR)/*/*/*.cpp)

SRC_C = $(wildcard $(SRC_DIR)/*.c)
SRC_C += $(wildcard $(SRC_DIR)/*/*.c)
SRC_C += $(wildcard $(SRC_DIR)/*/*/*.c)

OBJ_CPP = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_CPP))
OBJ_C = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_C))

TARGET = projet

all : mrproper run

run : build exe

build : $(OBJ_DIR)/$(TARGET)

$(OBJ_DIR)/$(TARGET): $(OBJ_CPP) $(OBJ_C)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) -c $< -o $@ $(CFLAGS)


clean :
	@if exist $(OBJ_DIR)\*.o @echo objects files deleted
	@if not exist $(OBJ_DIR)\*.o @echo no objects files
	@if exist $(OBJ_DIR)\*.o @del /Q $(OBJ_DIR)\*.o
	@for /d %%i in ($(OBJ_DIR)\*) do @(rmdir /s /q "%%i")

mrproper : clean
	@if exist $(OBJ_DIR)\$(TARGET).exe @echo exe file deleted
	@if not exist $(OBJ_DIR)\$(TARGET).exe @echo no exe file
	@if exist $(OBJ_DIR)\$(TARGET).exe @del /Q $(OBJ_DIR)\$(TARGET).exe

exe : $(OBJ_DIR)/$(TARGET)
	$(OBJ_DIR)/$(TARGET).exe
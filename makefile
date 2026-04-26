# ==============================================================================
# Makefile for ATLA RPG Project (ECE 205)
# Author: Edward Felipe III
# ==============================================================================

# Compiler and Flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
# Include directories: '.' for root, and specific subdirectories for headers
INCLUDES := -I. -ICharacters -IBendingSystem

# Target Executable Name
TARGET   := main

# Directory Structure
SRC_DIR  := .
PLAYER_CONTROLLED_DIR := Characters/PlayerControlled
GAME_CHAR_DIR := Characters
BEND_DIR := BendingSystem
OBJ_DIR  := obj

# Source Files
SRCS := $(SRC_DIR)/main.cpp \
        $(GAME_CHAR_DIR)/GameCharacter.cpp \
        $(PLAYER_CONTROLLED_DIR)/PlayerCharacter.cpp \
        $(PLAYER_CONTROLLED_DIR)/AirBender.cpp \
        $(PLAYER_CONTROLLED_DIR)/EarthBender.cpp \
        $(PLAYER_CONTROLLED_DIR)/FireBender.cpp \
        $(PLAYER_CONTROLLED_DIR)/WaterBender.cpp \
        $(BEND_DIR)/Bending_System.cpp \
        $(BEND_DIR)/Air_Bending.cpp \
        $(BEND_DIR)/Earth_Bending.cpp \
        $(BEND_DIR)/Fire_Bending.cpp \
        $(BEND_DIR)/Water_Bending.cpp

# Object Files (maps .cpp to .o in the OBJ_DIR)
OBJS := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Default Rule
all: $(TARGET)

# Link the Executable
$(TARGET): $(OBJS)
	@echo "Linking: $@"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@
	@echo "Build Successful!"

# Compile Source Files into Object Files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling: $<"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean Up Build Artifacts
clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Done."

# Run the Game
run: all
	./$(TARGET)

.PHONY: all clean run
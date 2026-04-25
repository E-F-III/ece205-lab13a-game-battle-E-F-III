# ==============================================================================
# Makefile for ATLA RPG Project (ECE 205)
# Author: Edward Felipe III
# ==============================================================================

# Compiler and Flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
# Include directories: '.' for root, and specific subdirectories for headers
INCLUDES := -I. -IAvatar/Characters -IAvatar/BendingSystem

# Target Executable Name
TARGET   := main

# Directory Structure
SRC_DIR  := .
CHAR_DIR := Avatar/Characters
BEND_DIR := Avatar/BendingSystem
OBJ_DIR  := obj

# Source Files
SRCS := $(SRC_DIR)/main.cpp \
        $(CHAR_DIR)/GameCharacter.cpp \
        $(CHAR_DIR)/PlayerCharacter.cpp \
        $(CHAR_DIR)/AirBender.cpp \
        $(CHAR_DIR)/EarthBender.cpp \
        $(CHAR_DIR)/FireBender.cpp \
        $(CHAR_DIR)/WaterBender.cpp \
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
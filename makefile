CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -ICharacters/PlayerControlled

TARGET = main

SRCS = main.cpp GameCharacter.cpp \
Characters/PlayerControlled/AirBender.cpp \
Characters/PlayerControlled/EarthBender.cpp \
Characters/PlayerControlled/FireBender.cpp \
Characters/PlayerControlled/WaterBender.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
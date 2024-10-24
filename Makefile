# Replace this with the path you get from `brew info sfml`
SFML_PATH = /opt/homebrew/Cellar/sfml/2.6.1

# Source files
CPP_FILES = $(wildcard *.cpp)

# Target executable
TARGET = bin/app

all: $(TARGET)

$(TARGET): $(CPP_FILES)
	mkdir -p bin
	g++ $(CPP_FILES) -I$(SFML_PATH)/include -o $(TARGET) -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

clean:
	rm -rf bin/*

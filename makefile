CC=g++
CPPFLAGS=-std=c++11 -Wall
LDFLAGS=-L/usr/local/lib -lcurl
SOURCES=src/restClient.cpp src/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/main.out

all:
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(SOURCES) -o $(EXECUTABLE)

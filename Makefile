INCLUDE_DIR=include
SOURCE_DIR=src
BUILD_DIR=build
TEST_DIR=test

CXX=g++ -std=c++11
CXXFLAGS=-O3 -I$(INCLUDE_DIR)
ifdef ($(_DEBUG))
	CXXFLAGS += -g
endif


all: akapi.o

akapi.o:$(SOURCE_DIR)/akapi.cpp $(INCLUDE_DIR)/akapi.h
	$(CXX) $(CXXFLAGS) -c $< -o $(BUILD_DIR)/$@


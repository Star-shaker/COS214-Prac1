CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -I.

SRC = main.cpp \
	  OpenCanvas/OpenCanvas.cpp \
	  Canvas/Canvas.cpp \
	  Shape/Shape.cpp \
	  Square/Square.cpp \
	  Rectangle/Rectangle.cpp \
	  Textbox/Textbox.cpp \
	  ShapeFactory/ShapeFactory.cpp \
	  SquareFactory/SquareFactory.cpp \
	  RectangleFactory/RectangleFactory.cpp \
	  TextboxFactory/TextboxFactory.cpp \
	  Memento/Memento.cpp \
	  Caretaker/Caretaker.cpp


OBJ = $(SRC:.cpp=.o)

TARGET = canvas_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
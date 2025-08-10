CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -I.
LDFLAGS =

SRC_COMMON = \
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
      Caretaker/Caretaker.cpp \
	  ExportCanvas/ExportCanvas.cpp \
	  PDFExporter/PDFExporter.cpp \
	  PNGExporter/PNGExporter.cpp

OBJ_COMMON = $(SRC_COMMON:.cpp=.o)

TARGET_TEST = canvas_test
TARGET_DEMO = canvas_demo

all: test

test: $(TARGET_TEST)
	./$(TARGET_TEST)

$(TARGET_TEST): main.cpp $(OBJ_COMMON)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ main.cpp $(OBJ_COMMON)

demo: $(TARGET_DEMO)
	./$(TARGET_DEMO)

$(TARGET_DEMO): demo.cpp $(OBJ_COMMON)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ demo.cpp $(OBJ_COMMON)

clean:
	rm -f $(OBJ_COMMON) $(TARGET_TEST) $(TARGET_DEMO)
	find . -name '*.gcda' -delete
	find . -name '*.gcno' -delete
	find . -name '*.gcov' -delete
	rm -f coverage.html

COVERAGE_FLAGS = --coverage

coverage-html: clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) $(COVERAGE_FLAGS)" LDFLAGS="$(LDFLAGS) $(COVERAGE_FLAGS)" $(TARGET_TEST)
	./$(TARGET_TEST)
	gcovr -r . --html -o coverage.html
	
valgrind-test: $(TARGET_TEST)
	valgrind --leak-check=full ./$(TARGET_TEST)

valgrind-demo: $(TARGET_DEMO)
	valgrind --leak-check=full ./$(TARGET_DEMO)
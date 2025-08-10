CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -I.
LDFLAGS =

SRC_COMMON = \
      OpenCanvas.cpp \
      Canvas.cpp \
      Shape.cpp \
      Square.cpp \
      Rectangle.cpp \
      Textbox.cpp \
      ShapeFactory.cpp \
      SquareFactory.cpp \
      RectangleFactory.cpp \
      TextboxFactory.cpp \
      Memento.cpp \
      Caretaker.cpp \
	  ExportCanvas.cpp \
	  PDFExporter.cpp \
	  PNGExporter.cpp

OBJ_COMMON = $(SRC_COMMON:.cpp=.o)

TARGET_TEST = canvas_test
TARGET_DEMO = canvas_demo

all: run

run: $(TARGET_TEST)
	./$(TARGET_TEST)

$(TARGET_TEST): TestingMain.cpp $(OBJ_COMMON)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ TestingMain.cpp $(OBJ_COMMON)

demo: $(TARGET_DEMO)
	./$(TARGET_DEMO)

$(TARGET_DEMO): DemoMain.cpp $(OBJ_COMMON)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ DemoMain.cpp $(OBJ_COMMON)

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
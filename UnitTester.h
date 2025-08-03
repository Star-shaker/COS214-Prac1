#ifndef "UNIT_TESTER"
#define "UNIT_TESTER"

#include <iostream>
#include <string>

template <typename T>
class UnitTester {
    private:
        int count;
        int success;
        void out(std::string);
    public:
        UnitTester();
        ~UnitTester();
        void test(T, T);
        void test(T[], T[]);
        void newSection(std::string);
        void endSection();
}

template <typename T>
UnitTester<T>::UnitTester() {}

UnitTester<T>::~UnitTester() {}

template <typename T>
void UnitTester<T>::test(T actual, T expected) {
    // TODO: test if equal operator defined
    count++;
    std::string message = "Test " + std::tostring(count);
    if (actual == expected) {
        success++;
        std::string message += " succeeded";
    } else {
        // TODO: catch cant convert to string errors
        std::string message += " failed\nExpected: " + expected + "\nActual: " + actual;
    }
    this->out(message);
}

template <typename T>
void UnitTester<T>::test(T[] actualList, T[] expectedList) {}

template <typename T>
void UnitTester<T>::newSection(String sectionName) {}

template <typename T>
void UnitTester<T>::endSection() {}

template <typename T>
void out(std::string toPrint) {
    std::cout << toPrint << std::endl;
}

#endif
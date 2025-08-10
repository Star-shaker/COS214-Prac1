#ifndef UNIT_TESTER_HPP
#define UNIT_TESTER_HPP

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class UnitTester {
private:
    int count_{0};               
    int success_{0};             
    std::string sectionName_;    

    // ANSI escape codes for colors and symbols
    static constexpr const char* COLOR_GREEN = "\033[32m";
    static constexpr const char* COLOR_RED   = "\033[31m";
    static constexpr const char* COLOR_RESET = "\033[0m";
    static constexpr const char* SYMBOL_OK   = "\u2714";  // ✓
    static constexpr const char* SYMBOL_FAIL = "\u2716";  // ✖

public:
    UnitTester() = default;

    ~UnitTester() = default;

    void newSection(const std::string& name) {
        sectionName_ = name;
        count_ = 0;
        success_ = 0;
        std::cout << "\n=== Section: " << sectionName_ << " ===" << std::endl;
    }

    void endSection() {
        int failed = count_ - success_;
        std::cout << "--- Summary for " << sectionName_
                  << ": " << count_ << " tests, "
                  << COLOR_GREEN << success_ << " passed" << COLOR_RESET << ", "
                  << COLOR_RED << failed  << " failed"  << COLOR_RESET
                  << " ---" << std::endl;
    }

    void test(const T& actual, const T& expected, const std::string& message = "") {
        ++count_;
        bool ok = (actual == expected);
        if (ok) ++success_;

        std::cout << "Test #" << count_;
        if (!message.empty()) std::cout << ": " << message;
        std::cout << " ";
        if (ok) {
            std::cout << COLOR_GREEN << SYMBOL_OK << " PASS" << COLOR_RESET;
        } else {
            std::cout << COLOR_RED << SYMBOL_FAIL << " FAIL" << COLOR_RESET
                      << " (Expected: " << expected
                      << ", Actual: "   << actual << ")";
        }
        std::cout << std::endl;
    }

    void test(const std::vector<T>& actualList,
              const std::vector<T>& expectedList,
              const std::string& message = "") {
        ++count_;
        bool ok = (actualList == expectedList);
        if (ok) ++success_;

        std::cout << "Test #" << count_;
        if (!message.empty()) std::cout << ": " << message;
        std::cout << " ";
        if (ok) {
            std::cout << COLOR_GREEN << SYMBOL_OK << " PASS" << COLOR_RESET;
        } else {
            std::cout << COLOR_RED << SYMBOL_FAIL << " FAIL" << COLOR_RESET;
            std::cout << " (Expected: [";
            for (size_t i = 0; i < expectedList.size(); ++i) {
                std::cout << expectedList[i];
                if (i + 1 < expectedList.size()) std::cout << ", ";
            }
            std::cout << "], Actual: [";
            for (size_t i = 0; i < actualList.size(); ++i) {
                std::cout << actualList[i];
                if (i + 1 < actualList.size()) std::cout << ", ";
            }
            std::cout << "])";
        }
        std::cout << std::endl;
    }
};

#endif 

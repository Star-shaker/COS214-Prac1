#ifndef UNIT_TESTER_HPP
#define UNIT_TESTER_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Header-only unit testing framework with colored output and tick/cross symbols.
 *
 * Usage:
 *   UnitTester<int> tester;
 *   tester.newSection("Integer Tests");
 *   tester.test(1 + 1, 2, "Addition test");
 *   tester.test(std::vector<int>{1,2,3}, std::vector<int>{1,2,3}, "Vector equality");
 *   tester.endSection();
 */
template <typename T>
class UnitTester {
private:
    int count_{0};               ///< Total number of tests in current section
    int success_{0};             ///< Number of passed tests in current section
    std::string sectionName_;    ///< Current section name

    // ANSI escape codes for colors and symbols
    static constexpr const char* COLOR_GREEN = "\033[32m";
    static constexpr const char* COLOR_RED   = "\033[31m";
    static constexpr const char* COLOR_RESET = "\033[0m";
    static constexpr const char* SYMBOL_OK   = "\u2714";  // ✓
    static constexpr const char* SYMBOL_FAIL = "\u2716";  // ✖

public:
    /**
     * @brief Default constructor.
     */
    UnitTester() = default;

    /**
     * @brief Destructor.
     */
    ~UnitTester() = default;

    /**
     * @brief Begin a new test section.
     * @param name Name of the test section.
     * Prints a header and resets counters.
     */
    void newSection(const std::string& name) {
        sectionName_ = name;
        count_ = 0;
        success_ = 0;
        std::cout << "\n=== Section: " << sectionName_ << " ===" << std::endl;
    }

    /**
     * @brief End the current test section and display summary.
     * Prints total tests, passed, and failed counts.
     */
    void endSection() {
        int failed = count_ - success_;
        std::cout << "--- Summary for " << sectionName_
                  << ": " << count_ << " tests, "
                  << COLOR_GREEN << success_ << " passed" << COLOR_RESET << ", "
                  << COLOR_RED << failed  << " failed"  << COLOR_RESET
                  << " ---" << std::endl;
    }

    /**
     * @brief Test equality of two single values.
     * @param actual   The actual value computed.
     * @param expected The expected value.
     * @param message  Optional description of the test.
     * Compares using operator== and prints colored pass/fail.
     */
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

    /**
     * @brief Test equality of two lists (vectors).
     * @param actualList   The actual vector computed.
     * @param expectedList The expected vector.
     * @param message      Optional description of the test.
     * Compares lengths and elements; prints colored pass/fail and mismatches.
     */
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

#endif // UNIT_TESTER_HPP

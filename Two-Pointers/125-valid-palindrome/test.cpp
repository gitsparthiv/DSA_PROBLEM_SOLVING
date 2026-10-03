#include <iostream>
#include <string>
#include "solution.cpp"

using namespace std;

void runTestCase(int testNum, string s, bool expected) {
    Solution sol;
    bool actual = sol.isPalindrome(s);
    
    bool passed = (actual == expected);
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    \"" << s << "\"\n";
        cout << "  Expected: " << (expected ? "true" : "false") << "\n";
        cout << "  Actual:   " << (actual ? "true" : "false") << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 125. Valid Palindrome ===\n\n";

    // Example 1
    runTestCase(1, "A man, a plan, a canal: Panama", true);

    // Example 2
    runTestCase(2, "race a car", false);

    // Example 3
    runTestCase(3, " ", true);

    // Edge Cases
    runTestCase(4, "0P", false);
    runTestCase(5, "a.", true);

    return 0;
}

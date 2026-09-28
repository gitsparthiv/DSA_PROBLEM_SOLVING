#include <iostream>
#include <vector>
#include <string>
#include "solution.cpp"

using namespace std;

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ", ";
    }
    cout << "]";
}

void runTestCase(int testNum, vector<int> nums, int expected) {
    Solution sol;
    int actual = sol.longestConsecutive(nums);
    
    bool passed = (actual == expected);
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    "; printVector(nums); cout << "\n";
        cout << "  Expected: " << expected << "\n";
        cout << "  Actual:   " << actual << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 128. Longest Consecutive Sequence ===\n\n";

    // Example 1
    runTestCase(1, {100, 4, 200, 1, 3, 2}, 4);

    // Example 2
    runTestCase(2, {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9);

    // Example 3
    runTestCase(3, {1, 0, 1, 2}, 3);

    // Edge Cases
    runTestCase(4, {}, 0);
    runTestCase(5, {10}, 1);

    return 0;
}

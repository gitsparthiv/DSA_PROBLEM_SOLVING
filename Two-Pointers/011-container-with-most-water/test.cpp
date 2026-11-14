#include <iostream>
#include <vector>
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

void runTestCase(int testNum, vector<int> height, int expected) {
    Solution sol;
    int actual = sol.maxArea(height);
    
    bool passed = (actual == expected);
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    "; printVector(height); cout << "\n";
        cout << "  Expected: " << expected << "\n";
        cout << "  Actual:   " << actual << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 11. Container With Most Water ===\n\n";

    // Example 1
    runTestCase(1, {1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);

    // Example 2
    runTestCase(2, {1, 1}, 1);

    // Additional Test Cases
    runTestCase(3, {4, 3, 2, 1, 4}, 16);
    runTestCase(4, {1, 2, 1}, 2);

    return 0;
}

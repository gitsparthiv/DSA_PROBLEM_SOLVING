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
    int actual = sol.trap(height);
    
    bool passed = (actual == expected);
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    height = "; printVector(height); cout << "\n";
        cout << "  Expected: " << expected << "\n";
        cout << "  Actual:   " << actual << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 42. Trapping Rain Water ===\n\n";

    // Example 1
    runTestCase(1, {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);

    // Example 2
    runTestCase(2, {4, 2, 0, 3, 2, 5}, 9);

    // Edge Case 1: Less than 3 bars cannot trap water
    runTestCase(3, {3}, 0);
    runTestCase(4, {3, 2}, 0);

    // Edge Case 2: Monotonic descending / ascending
    runTestCase(5, {5, 4, 3, 2, 1}, 0);
    runTestCase(6, {1, 2, 3, 4, 5}, 0);

    // Edge Case 3: Simple valley
    runTestCase(7, {2, 0, 2}, 2);

    return 0;
}

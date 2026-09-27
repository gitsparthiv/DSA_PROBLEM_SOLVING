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

void runTestCase(int testNum, vector<int> nums, vector<int> expected) {
    Solution sol;
    vector<int> actual = sol.productExceptSelf(nums);
    
    bool passed = (actual == expected);
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    "; printVector(nums); cout << "\n";
        cout << "  Expected: "; printVector(expected); cout << "\n";
        cout << "  Actual:   "; printVector(actual); cout << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 238. Product of Array Except Self ===\n\n";

    // Example 1
    runTestCase(1, {1, 2, 3, 4}, {24, 12, 8, 6});

    // Example 2
    runTestCase(2, {-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0});

    return 0;
}

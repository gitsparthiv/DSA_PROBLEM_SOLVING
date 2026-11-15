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

void runTestCase(int testNum, vector<int> numbers, int target, vector<int> expected) {
    Solution sol;
    vector<int> actual = sol.twoSum(numbers, target);
    
    bool passed = (actual == expected);
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    numbers = "; printVector(numbers); cout << ", target = " << target << "\n";
        cout << "  Expected: "; printVector(expected); cout << "\n";
        cout << "  Actual:   "; printVector(actual); cout << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 167. Two Sum II - Input Array Is Sorted ===\n\n";

    // Example 1
    runTestCase(1, {2, 7, 11, 15}, 9, {1, 2});

    // Example 2
    runTestCase(2, {2, 3, 4}, 6, {1, 3});

    // Example 3
    runTestCase(3, {-1, 0}, -1, {1, 2});

    return 0;
}

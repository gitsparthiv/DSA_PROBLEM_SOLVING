#include <iostream>
#include <vector>
#include <algorithm>
#include "solution.cpp"

using namespace std;

vector<int> canonicalize(vector<int> vec) {
    sort(vec.begin(), vec.end());
    return vec;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ", ";
    }
    cout << "]";
}

void runTestCase(int testNum, vector<int> nums, int k, vector<int> expected) {
    Solution sol;
    vector<int> actual = sol.topKFrequent(nums, k);
    
    bool passed = (canonicalize(actual) == canonicalize(expected));
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    nums = "; printVector(nums); cout << ", k = " << k << "\n";
        cout << "  Expected: "; printVector(expected); cout << "\n";
        cout << "  Actual:   "; printVector(actual); cout << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 347. Top K Frequent Elements ===\n\n";

    // Example 1
    runTestCase(1, {1, 1, 1, 2, 2, 3}, 2, {1, 2});

    // Example 2
    runTestCase(2, {1}, 1, {1});

    // Example 3: Negative numbers
    runTestCase(3, {-1, -1, 2}, 1, {-1});

    // Example 4: Distinct frequencies
    runTestCase(4, {4, 1, -1, 2, -1, 2, 3}, 2, {-1, 2});

    // Example 5: k equals number of unique elements
    runTestCase(5, {5, 3, 1, 1, 1, 3, 73, 1}, 2, {1, 3});

    return 0;
}

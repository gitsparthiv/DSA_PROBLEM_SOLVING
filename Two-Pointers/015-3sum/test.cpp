#include <iostream>
#include <vector>
#include <algorithm>
#include "solution.cpp"

using namespace std;

void normalize(vector<vector<int>>& triplets) {
    for (auto& t : triplets) {
        sort(t.begin(), t.end());
    }
    sort(triplets.begin(), triplets.end());
}

void printTriplets(const vector<vector<int>>& triplets) {
    cout << "[";
    for (size_t i = 0; i < triplets.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < triplets[i].size(); ++j) {
            cout << triplets[i][j] << (j + 1 < triplets[i].size() ? "," : "");
        }
        cout << "]" << (i + 1 < triplets.size() ? ", " : "");
    }
    cout << "]";
}

void runTestCase(int testNum, vector<int> nums, vector<vector<int>> expected) {
    Solution sol;
    vector<vector<int>> actual = sol.threeSum(nums);
    
    vector<vector<int>> normActual = actual;
    vector<vector<int>> normExpected = expected;
    normalize(normActual);
    normalize(normExpected);
    
    bool passed = (normActual == normExpected);
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    ";
        cout << "[";
        for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << (i + 1 < nums.size() ? ", " : "");
        cout << "]\n";
        cout << "  Expected: "; printTriplets(expected); cout << "\n";
        cout << "  Actual:   "; printTriplets(actual); cout << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 15. 3Sum ===\n\n";

    // Example 1
    runTestCase(1, {-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});

    // Example 2
    runTestCase(2, {0, 1, 1}, {});

    // Example 3
    runTestCase(3, {0, 0, 0}, {{0, 0, 0}});

    return 0;
}

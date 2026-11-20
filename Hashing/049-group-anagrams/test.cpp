#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "solution.cpp"

using namespace std;

vector<vector<string>> canonicalize(vector<vector<string>> groups) {
    for (auto& group : groups) {
        sort(group.begin(), group.end());
    }
    sort(groups.begin(), groups.end());
    return groups;
}

void printGroups(const vector<vector<string>>& groups) {
    cout << "[";
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < groups[i].size(); ++j) {
            cout << "\"" << groups[i][j] << "\"";
            if (j + 1 < groups[i].size()) cout << ", ";
        }
        cout << "]";
        if (i + 1 < groups.size()) cout << ", ";
    }
    cout << "]";
}

void runTestCase(int testNum, vector<string> strs, vector<vector<string>> expected) {
    Solution sol;
    vector<vector<string>> actual = sol.groupAnagrams(strs);
    
    bool passed = (canonicalize(actual) == canonicalize(expected));
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Input:    ";
        cout << "[";
        for (size_t i = 0; i < strs.size(); ++i) {
            cout << "\"" << strs[i] << "\"" << (i + 1 < strs.size() ? ", " : "");
        }
        cout << "]\n";
        cout << "  Expected: "; printGroups(expected); cout << "\n";
        cout << "  Actual:   "; printGroups(actual); cout << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 49. Group Anagrams ===\n\n";

    // Example 1
    runTestCase(1, {"eat", "tea", "tan", "ate", "nat", "bat"}, {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}});

    // Example 2
    runTestCase(2, {""}, {{""}});

    // Example 3
    runTestCase(3, {"a"}, {{"a"}});

    // Example 4: Words with duplicate characters
    runTestCase(4, {"bdddddddddd", "bbbbbbbbbbc"}, {{"bdddddddddd"}, {"bbbbbbbbbbc"}});

    // Example 5: All anagrams
    runTestCase(5, {"ab", "ba"}, {{"ab", "ba"}});

    return 0;
}

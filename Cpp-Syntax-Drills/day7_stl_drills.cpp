#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

// ============================================================================
// DRILL 1: Empty Vector vs Pre-sized Vector
// Goal:
//   1. Create an empty vector `a` and push_back 10, 20, 30 into it.
//   2. Create a vector `b` of size `n` pre-filled with -1, then set index 2 to 99.
//   3. Return {a, b}.
// ============================================================================
pair<vector<int>, vector<int>> drill1_vectors(int n) {
   vector<int> a;
   a.push_back(10);
   a.push_back(20);
   a.push_back(30);
   vector<int> b(n, -1);
   b[2] = 99;
   return {a,b};
}
// ============================================================================
// DRILL 2: Frequency Map & Safe Lookup (Avoiding the [] Insertion Trap)
// Goal:
//   1. Count the frequency of every word in `words` using an unordered_map.
//   2. Check if `query` exists in the map WITHOUT accidentally inserting it.
//      If found, store its count in `freq`; otherwise set `freq = -1`.
//   3. Return {freq, (int)mp.size()}.
// ============================================================================
pair<int, int> drill2_safeMap(const vector<string>& words, const string& query) {
   unordered_map<string,int> mp;
   int freq;
   for(string word : words){
    mp[word]++;
   }
   if(mp.find(query) != mp.end()){
    freq = mp[query];
   }
   else{
    freq = -1;
   }
   return {freq, (int)mp.size()};
}

// ============================================================================
// DRILL 3: 2D Dynamic Buckets (vector<vector<string>>)
// Goal:
//   1. Create `buckets` sized to hold indices 0 through `maxLen` (inclusive!).
//   2. Use a range-based loop over `words` (by const reference!) and push each
//      word into the bucket at index `word.size()`.
//   3. Return `buckets`.
// ============================================================================
vector<vector<string>> drill3_buckets(const vector<string>& words, int maxLen) {
    // TODO: Write your code here
    return {};
}

// ============================================================================
// DRILL 4: Reference Mutation (&) vs Local Copy Sorting
// Goal A: Multiply every element in `nums` by 2 IN-PLACE using a range loop
//         with a reference (`int&`).
// Goal B: Given `const string& original`, create a local copy, sort its
//         characters alphabetically, and return the sorted copy.
// ============================================================================
void drill4a_doubleInPlace(vector<int>& nums) {
    // TODO: Write your code here
}

string drill4b_sortedCopy(const string& original) {
    // TODO: Write your code here
    return "";
}

// ============================================================================
// TEST HARNESS (Do not modify below)
// ============================================================================
int main() {
    cout << "=== Day 7: C++ STL Syntax Micro-Drills ===\n\n";

    // Test Drill 1
    auto d1 = drill1_vectors(4);
    vector<int> exp1a = {10, 20, 30};
    vector<int> exp1b = {-1, -1, 99, -1};
    cout << "Drill 1 (Vectors):       "
         << ((d1.first == exp1a && d1.second == exp1b) ? "[PASSED]" : "[FAILED]") << "\n";

    // Test Drill 2
    vector<string> words2 = {"go", "rust", "go", "cpp"};
    auto d2a = drill2_safeMap(words2, "go");
    auto d2b = drill2_safeMap(words2, "java"); // Must NOT be inserted! Size must stay 3!
    cout << "Drill 2 (Safe Map):      "
         << ((d2a == make_pair(2, 3) && d2b == make_pair(-1, 3)) ? "[PASSED]" : "[FAILED]") << "\n";

    // Test Drill 3
    vector<string> words3 = {"a", "cat", "hi", "dog"};
    auto d3 = drill3_buckets(words3, 3);
    bool pass3 = (d3.size() == 4 &&
                  d3[0].empty() &&
                  d3[1] == vector<string>{"a"} &&
                  d3[2] == vector<string>{"hi"} &&
                  d3[3] == vector<string>{"cat", "dog"});
    cout << "Drill 3 (2D Buckets):    " << (pass3 ? "[PASSED]" : "[FAILED]") << "\n";

    // Test Drill 4
    vector<int> nums4 = {1, 5, 10};
    drill4a_doubleInPlace(nums4);
    string orig = "dcba";
    string sortedS = drill4b_sortedCopy(orig);
    bool pass4 = (nums4 == vector<int>{2, 10, 20} && orig == "dcba" && sortedS == "abcd");
    cout << "Drill 4 (Ref & Sort):    " << (pass4 ? "[PASSED]" : "[FAILED]") << "\n";

    return 0;
}

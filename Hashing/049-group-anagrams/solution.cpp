#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
            for(int i = 0; i < strs.size(); i++){
                string str = strs[i];
                sort(str.begin(), str.end());
                map[str].push_back(strs[i]);
            }
            for (auto& pair : map) {
    result.push_back(pair.second);
}
        return {result};
    }
};

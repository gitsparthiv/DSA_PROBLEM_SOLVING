#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> count;
            vector<vector<int>>buckets(nums.size() + 1); 
            for(int num : nums){
                count[num]++;
            }
            for(auto& pair : count){
                buckets[pair.second].push_back(pair.first);
            }
                vector<int> result;
for (int i = nums.size(); i >= 1; i--) {
    for (int num : buckets[i]) {
        result.push_back(num);
        if (result.size() == k) {
            return result;
        }
    }
}

return result;
            }
        
};

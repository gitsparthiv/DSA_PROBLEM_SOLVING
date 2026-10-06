#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
      for(int i = 0; i < nums.size(); i++){
         if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
    }
        int complement = -nums[i];
        int left = 0;
             left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            int res = nums[left] + nums[right];
            if(res == complement){
                result.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;
                while(left < right && nums[left] == nums[left - 1]){
                    left++;
                }
                while(left < right && nums[right] == nums[right + 1]){
                    right--;
                }
            }
            if(res < complement){
                left++;
            }
            if(res > complement){
                right--;
            }
        }
      }
      return result;  
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while(left < right){
            int currentArea = (right - left) * min(height[left], height[right]);
            maxWater = max(maxWater,currentArea);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};

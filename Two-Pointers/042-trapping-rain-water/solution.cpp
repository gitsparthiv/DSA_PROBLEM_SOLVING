#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int totalwater = 0;
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = height[left];
        int maxRight = height[right];
        while(left < right){
        int currentwater = 0;
        if(maxLeft <= maxRight){
            left++;
            if(height[left] > maxLeft){
                maxLeft = height[left];
            }
            else{
                currentwater = min(maxLeft, maxRight) - height[left];
            }
        }
        else if(maxRight < maxLeft){
            right--;
            if(height[right] > maxRight){
                maxRight = height[right];
            }
            else{
                currentwater = min(maxLeft, maxRight) - height[right];
            }
        }
        if(currentwater > 0){
            totalwater = totalwater + currentwater;
        }
    }
        return totalwater;
    }
};

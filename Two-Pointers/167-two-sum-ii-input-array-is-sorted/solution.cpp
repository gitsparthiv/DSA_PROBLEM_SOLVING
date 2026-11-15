#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            int currentsum = numbers[left] + numbers[right]; 
            if(currentsum == target){
                return {left + 1, right + 1};
            }
            if(currentsum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {left + 1,right + 1};
    }
};

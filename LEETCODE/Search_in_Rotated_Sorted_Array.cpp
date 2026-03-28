
class Solution {
public:
    int findMin(vector<int>& nums) {
        int target = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                target = i;
                break;
            }
        }
        int lowest = 0;
        if(target == 0){
           if(nums.size() == 1){
             return lowest = nums[0];
           } 
           else if(nums[target] <= nums[target + 1]){
            return lowest = nums[0];
           }
        }
        lowest = nums[target + 1];
        return lowest;
        return -1;
    }
};

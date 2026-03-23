class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int n =nums.size();
  while(i < n){
    if(nums[i] == target)
    {
        return i;
    }
    else
    {
        i++;
    }
    }
    return -1;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxstreak = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int currentstreak = 0;
            if (numSet.find(nums[i] - 1) == numSet.end())
            {
                currentstreak++;
                for (int j = 1; j < nums.size(); j++)
                {
                    if (numSet.find(nums[i] + j) != numSet.end())
                    {
                        currentstreak++;
                    }
                    else if ((numSet.find(nums[i] + j) == numSet.end()))
                    {
                        break;
                    }
                }
            }
            else if (numSet.find(nums[i] - 1) != numSet.end())
            {
                continue;
            }
            maxstreak = max(currentstreak, maxstreak);
        }
        return maxstreak;
    }
};

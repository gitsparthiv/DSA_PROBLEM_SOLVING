#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxstreak = 0;
        for (int num:numSet)
        {
            
            if (numSet.find(num - 1) == numSet.end())
            {
                int currentNum = num;
                int currentStreak = 1;
              while(numSet.find(currentNum + 1) != numSet.end())
                {
                     currentNum++;
                    currentStreak++;
                }
                maxstreak = max(currentStreak, maxstreak);
            }
        }
        return maxstreak;
    }
};

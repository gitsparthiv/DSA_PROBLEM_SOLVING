// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters if it is non-empty.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    if(strs[0] == result){
        return result;
        int i = 0;
    }
        for(int j = 0; j < strs[0].size(); j++)
        {
         for(int i = 0; i < strs.size() - 1; i++)
         {
            
            if(strs[i][j] == strs[i+1][j]){
                continue;
            }
            else{
                return result;
            }
         }
         result = result + strs[strs.size() - 1][j];
        }
        return result;
    }
};

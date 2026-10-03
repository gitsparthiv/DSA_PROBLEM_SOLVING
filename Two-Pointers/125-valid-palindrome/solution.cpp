#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left]) == tolower(s[right])){
                left++;
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }   
        }
        return true;
    }
};

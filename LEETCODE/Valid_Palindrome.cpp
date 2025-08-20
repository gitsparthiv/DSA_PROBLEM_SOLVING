class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
while(right >= left){
    while(left <= right && isalnum(s[left]) == 0)
    {
        left++;
    }
    while(left <= right && isalnum(s[right]) == 0)
    {
        right--;
    }
    if(right >= left){
    s[left] = tolower(s[left]);
    s[right] = tolower(s[right]);
    if(s[left] == s[right]){
        left++;
        right--;
        continue;
    }
    else{
        return false;
    }
    }
}
return true;     
    }
};

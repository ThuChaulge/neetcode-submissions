class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left < right) {
            while (left < right && !isalnum(static_cast<char>(s[left]))) left++;
            while (left < right && !isalnum(static_cast<char>(s[right]))) right--;
            if (static_cast<char>(tolower(s[left]) != static_cast<char>(tolower(s[right]))))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

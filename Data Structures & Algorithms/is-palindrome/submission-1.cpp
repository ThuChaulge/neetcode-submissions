class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char x : s) {
            if (x >= 'A' && x <= 'Z') {
                x = tolower(x);
            }
            if ((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9')) {
                str += x;
            }
        }
        int n = str.size();
        for (int i = 0; i < n/2; i++) {
            if (str[i] != str[n-1-i]) {
                return false;
            }
        }
        return true;
    }
};

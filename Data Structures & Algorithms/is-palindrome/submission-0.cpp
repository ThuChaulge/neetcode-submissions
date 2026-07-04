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
        string str1 = str;
        reverse(str1.begin(), str1.end());
        cout << "str = " << str << " str1 = " << str1 << endl;
        return str == str1;
    }
};

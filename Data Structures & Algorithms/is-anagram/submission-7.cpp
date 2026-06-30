class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int arr_s[26] = {0};
        int arr_t[26] = {0};
        int n = s.size();
        for (int i = 0; i < n; i++) {
            arr_s[s[i] - 'a']++;
            arr_t[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr_s[i] != arr_t[i]) {
                cout << arr_s[i] << " " << arr_t[i] << endl;
                return false;
            }
        }
        return true;
    }
};

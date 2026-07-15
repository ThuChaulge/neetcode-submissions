class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 != 0) return false;

        unordered_map<char, char> mp = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;

                char c = st.top();
                auto it = mp.find(c);
                
                if (it != mp.end() && it->second == s[i]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

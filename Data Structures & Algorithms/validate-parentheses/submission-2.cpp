class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 != 0) return false;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                char c = st.top();
                if ((c == '(' && s[i] != ')') || (c == '{' && s[i] != '}') || (c == '[' && s[i] != ']')) return false;
                st.pop();
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size());
        
        for (const string& s: tokens) {
            if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '/' || s[0] == '*')) {
                int num1 = st.back(); st.pop_back();
                int num2 = st.back(); st.pop_back();

                switch (s[0]) {
                    case '+': st.push_back(num2+num1); break;
                    case '-': st.push_back(num2-num1); break;
                    case '*': st.push_back(num2*num1); break;
                    case '/': st.push_back(num2/num1); break;
                }
            } else {
                int val = 0;
                from_chars(s.data(), s.data() + s.size(), val);
                st.push_back(val);
            }
        }
        return st.back();
    }
};

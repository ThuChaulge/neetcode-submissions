class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        
        for (int i = 0; i < n; i++) {
            string c = tokens[i];
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                if (s.empty()) continue;
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if (c == "+") {
                    s.push(num1 + num2);
                } else if (c == "-") {
                    s.push(num2 - num1);
                } else if (c == "*") {
                    s.push(num1 * num2);
                } else if (c == "/") {
                    s.push(num2/num1);
                }
            } else {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};

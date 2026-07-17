class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty()) s.push(i);
            else {
                while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                    int top = s.top();
                    s.pop();
                    result[top] = i - top;
                }
                s.push(i);
            }
        }
        while (!s.empty()) {
            result[s.top()] = 0;
            s.pop();
        }
        return result;
    }
};

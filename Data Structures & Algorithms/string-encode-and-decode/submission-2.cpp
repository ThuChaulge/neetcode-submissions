class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (string s: strs) {
            result += to_string(s.size()) + '#' + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        int n = s.size();

        vector<string> result;
        int i = 0;

        while (i < n) {
            int j = s.find('#', i);
            int lengh = stoi(s.substr(i, j-i));
            i = j+1;
            result.push_back(s.substr(i, lengh));
            i += lengh;
        }
        return result;
    }
};

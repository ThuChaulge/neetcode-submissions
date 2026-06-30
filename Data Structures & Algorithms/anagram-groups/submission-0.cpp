class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> result;
        for (auto x : mp) {
            vector<string> group;
            for (int i = 0; i < x.second.size(); i++) {
                group.push_back(strs[x.second[i]]);
            }
            result.push_back(group);
        }
        return result;
    }
};
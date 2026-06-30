class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        mp.reserve(strs.size());
        int n = strs.size();
        int count[26];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; ++j) count[j] = 0;
            for (char c : strs[i]) {
                count[c - 'a']++;
            }
            string key = "";
            key.reserve(strs[i].length());
            for (int j = 0; j < 26; j++) {
                if (count[j] > 0) {
                    key.append(count[j], (char)('a' + j));
                }
            }
            mp[key].push_back(i);
        }
        vector<vector<string>> result;
        result.reserve(mp.size());
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<string> group;
            group.reserve(it->second.size());
            for (int idx : it->second) {
                group.push_back(strs[idx]);
            }
            result.push_back(move(group));
        }
        return result;
    }
};
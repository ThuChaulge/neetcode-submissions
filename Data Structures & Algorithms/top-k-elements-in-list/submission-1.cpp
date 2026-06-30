class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }

        vector<pair<int, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [] (const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second;
        });

        vector<int> result;
        auto it = vec.begin();
        while (k-- > 0) {
            result.push_back(it->first);
            it++;
        }
        return result;
    }
};

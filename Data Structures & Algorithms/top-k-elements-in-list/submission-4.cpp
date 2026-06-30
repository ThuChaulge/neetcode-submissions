class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const int& num : nums) {
            counts[num]++;
        }

        map<int, vector<int>, std::greater<int>> mp;
        for (auto x : counts) {
            mp[x.second].push_back(x.first);
        }

        vector<int> result;
        int count = 0;
        for (auto e : mp) {
            for (auto x : e.second) {
                result.push_back(x);
                count++;
                if (count == k) break;
            }
            if (count == k) break;
        }

        return result;
    }
};

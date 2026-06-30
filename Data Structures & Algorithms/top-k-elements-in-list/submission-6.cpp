class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const int& num : nums) {
            counts[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        for (const auto& [num, count] : counts) {
            buckets[count].push_back(num);
        }

        vector<int> result;
        result.reserve(k);
        for (int i = n; i >= 0 && result.size() < k; i--) {
            if (!buckets[i].empty()) {
                for (const int& num: buckets[i]) {
                    result.push_back(num);
                    if (result.size() == k) {
                        break;
                    }
                }
            }
        }
        return result;
    }
};

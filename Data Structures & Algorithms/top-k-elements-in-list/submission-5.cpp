class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const int& num : nums) {
            counts[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        for (const auto& [num, count] : counts) {
            min_heap.push({count, num});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> result;
        result.reserve(k);
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};

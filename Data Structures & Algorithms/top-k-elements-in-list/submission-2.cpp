class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        unordered_map<int, int> counts;
        for (const int& num : nums) {
            counts[num]++;
        }

        // Mảng các xô: index là tần suất (từ 0 đến n), giá trị là danh sách các số
        vector<vector<int>> buckets(n + 1);
        for (const auto& [num, count] : counts) {
            buckets[count].push_back(num);
        }

        // Duyệt ngược từ tần suất cao nhất (n) về thấp nhất (0)
        vector<int> result;
        result.reserve(k);
        
        for (int freq = n; freq >= 0 && result.size() < k; --freq) {
            if (!buckets[freq].empty()) {
                for (const int& num : buckets[freq]) {
                    result.push_back(num);
                    if (result.size() == k) break;
                }
            }
        }

        return result;
    }
};

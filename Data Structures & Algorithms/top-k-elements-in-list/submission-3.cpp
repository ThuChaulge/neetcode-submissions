class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
        // Tối ưu hóa I/O cho các bài toán nhiều testcase hoặc input lớn
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Bước 1: Đếm tần suất
        unordered_map<int, int> counts;
        for (const int& num : nums) {
            counts[num]++;
        }

        // Bước 2: Duy trì Min-Heap kích thước K
        // Pair: {tần suất, giá trị phần tử} -> priority_queue mặc định so sánh theo trị đầu tiên
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (const auto& [num, count] : counts) {
            min_heap.push({count, num});
            if (min_heap.size() > k) {
                min_heap.pop(); // Loại bỏ phần tử có tần suất thấp nhất hiện tại
            }
        }

        // Bước 3: Trích xuất kết quả
        vector<int> result;
        result.reserve(k); // Tối ưu bộ nhớ, tránh reallocate
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return result;
    }
};

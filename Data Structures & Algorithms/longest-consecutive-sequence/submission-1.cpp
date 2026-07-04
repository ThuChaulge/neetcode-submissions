class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int res = 1;
        for (int i = 0; i < n; i++) {
            if (s.find(nums[i]-1) != s.end()) {
                continue;
            }
            int cons_length = 1;
            int start = nums[i];
            start++;
            while(s.find(start) != s.end()) {
                cons_length++;
                start++;
            } 
            res = max(res, cons_length);
        }
        return res;
    }
};

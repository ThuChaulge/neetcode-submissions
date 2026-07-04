class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> s;
        s.reserve(n);
        for (int x : nums) {
            s.insert(x);
        }

        int res = 1;
        for (int x : s) {
            if (s.find(x-1) != s.end()) {
                continue;
            }
            int cons_length = 1;
            while(s.find(++x) != s.end()) {
                cons_length++;
            } 
            res = max(res, cons_length);
        }
        return res;
    }
};

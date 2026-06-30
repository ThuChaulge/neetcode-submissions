class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int other = target-nums[i];
            if (mp[other].size() != 0) {
                for (auto x : mp[other]) {
                    if (x > i) {
                        return {i, x};
                    } 
                }
            }
        }
    }
};

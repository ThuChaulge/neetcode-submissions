class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[nums[0]] = 1;
        for (int i = 1; i < n; i++) {
            int other = target - nums[i];
            if (mp[other] != 0) {
                return {mp[other]-1, i};
            }
            if (mp[nums[i]] == 0) {
                mp[nums[i]] = i+1;
            }
        }
        
        return {0,1};
    }
};

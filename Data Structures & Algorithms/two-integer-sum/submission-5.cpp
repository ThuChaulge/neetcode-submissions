class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp.reserve(n);
        for (int i = 0; i < n; i++) {
            int other = target - nums[i];
            auto it = mp.find(other);
            if (it != mp.end()) {
                return {it->second, i};
            }
            mp[nums[i]] = i;
        }
        
        return {};
    }
};

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        if (nums.size() != s.size()) return true;
        return false;
    }
};
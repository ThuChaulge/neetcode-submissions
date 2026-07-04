class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int right = n-1;
            while (right > i) {
                if (target - numbers[i] == numbers[right] && numbers[i] != numbers[right]) {
                    return {i+1, right+1};
                }
                right--;
            }
        }
        return {};
    }
};

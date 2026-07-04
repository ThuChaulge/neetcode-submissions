class Solution {
public:
    int binarySearch(vector<int>& numbers, int x, int l, int r) {
        while (l <= r) {
            int m = l + (r-l)/2;
            if (numbers[m] == x) {
                return m;
            }
            if (x < numbers[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int other = target - numbers[i];
            int idx = binarySearch(numbers, other, i+1, n-1);
            if (idx != -1) {
                return {i+1, idx+1};
            }
        }
        return {};
    }
};

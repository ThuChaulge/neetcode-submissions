class Solution {
public:
    int binarySearch(vector<int>& numbers, int x) {
        int l = 0;
        int r = numbers.size()-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (numbers[m] == x) {
                return m;
            }
            if (numbers[m] > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int other = target - numbers[i];
            if (other <= numbers[i]) break;
            int index = binarySearch(numbers, other);
            if (index != -1) {
                return {i+1, index+1};
            }
        }
        return {};
    }
};

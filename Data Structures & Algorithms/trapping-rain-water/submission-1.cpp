class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        for (int i = 0; i < n-1; i++) {
            left_max[i+1] = max(left_max[i], height[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            right_max[i-1] = max(right_max[i], height[i]);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            int temp = min (left_max[i], right_max[i]) - height[i];
            if (temp > 0) result += temp;
        }
        return result;
    }
};

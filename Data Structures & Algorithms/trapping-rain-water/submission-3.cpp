class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        vector<int> right_max(n, 0);
        right_max[n-1] = height[n-1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        int total_water = 0;
        int left_max = 0;
        for (int i = 0; i < n; i++) {
            left_max = max(left_max, height[i]);
            total_water += min(left_max, right_max[i]) - height[i];
        }
        return total_water;
    }
};

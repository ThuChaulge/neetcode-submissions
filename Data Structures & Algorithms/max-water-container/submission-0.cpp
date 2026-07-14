class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int max_water = 0;
        int left = 0, right = n-1;
        while (left < right) {
            int current_water = min(heights[left], heights[right]) * (right - left);
            max_water = max(max_water, current_water);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_water;
    }
};

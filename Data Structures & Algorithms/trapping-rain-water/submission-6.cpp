class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        
        int total_water = 0;
        
        stack<int> s;
        int i = 0;
        while (i < n) {
            while (i < n && (s.empty() || (height[i] <= height[s.top()]))) s.push(i++);
            if (i < n && height[i] > height[s.top()]) {
                while(!s.empty() && height[i] >= height[s.top()]) {
                    int bottom = s.top();
                    s.pop();
                    if (!s.empty()) {
                        int left = s.top();
                        int width = i - left - 1;
                        int high = min(height[left], height[i]) - height[bottom];
                        total_water += width * high;
                    }
                }
                s.push(i);
                i++;
            }
        }
    
        return total_water;
    }
};

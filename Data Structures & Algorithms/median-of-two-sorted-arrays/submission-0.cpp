class Solution {
public:
    double find(vector<int>& min_nums, vector<int>& max_nums) {
        int m = min_nums.size(), n = max_nums.size();
        int left_size = (m + n + 1)/2;
        int low = 0, high = m;
        while (low <= high) {
            int i = (low + high)/2, j = left_size - i;
            int maxLeft1 = i == 0 ? INT_MIN : min_nums[i-1];
            int maxLeft2 = j == 0 ? INT_MIN : max_nums[j-1];
            int minRight1 = i == m ? INT_MAX : min_nums[i];
            int minRight2 = j == n ? INT_MAX : max_nums[j];
            if (maxLeft1 > minRight2) {
                high = i - 1;
            } else if (maxLeft2 > minRight1 ) {
                low = i + 1;
            } else {
                double result = 0;
                if ((m + n) % 2 == 0) {
                    result = (max(maxLeft1, maxLeft2) + min(minRight1,minRight2))*1.0/2;
                } else{
                    result = max(maxLeft1, maxLeft2);
                }
                return result;
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            return find(nums1, nums2);
        } else {
            return find(nums2, nums1);
        }
        
        
    }
};

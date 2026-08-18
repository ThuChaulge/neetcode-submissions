class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n-1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (matrix[mid][0] <= target && target <= matrix[mid][m-1]) {
                int l_row = 0, r_row = m-1;
                while (l_row <= r_row) {
                    int m_row = l_row + (r_row - l_row)/2;
                    if (matrix[mid][m_row] == target) {
                        return true;
                    } else if (target < matrix[mid][m_row]) {
                        r_row = m_row - 1;
                    } else {
                        l_row = m_row + 1;
                    }
                }
                return false;
            } else if (target < matrix[mid][0]) {
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        return false;
    }
};

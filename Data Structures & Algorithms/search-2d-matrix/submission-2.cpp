class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = n*m -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            int row = mid/n, col = mid % n;
            if (target == matrix[row][col]) {
                return true;
            } else if (target < matrix[row][col]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};


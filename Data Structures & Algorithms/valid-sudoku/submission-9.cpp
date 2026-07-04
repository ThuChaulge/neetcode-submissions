class Solution {
public:
bool isValidSudoku(const vector<vector<char>>& board) {
        // Tối ưu hóa I/O tốc độ cao cho CP
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Sử dụng mảng int lưu Bitmask thay vì mảng bool nhị phân
        // Mỗi hàng/cột/sub-box sẽ quản lý trạng thái bằng 1 số nguyên duy nhất.
        int row_mask[9] = {0};
        int col_mask[9] = {0};
        int box_mask[9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                // Ánh xạ số từ 0 -> 8 tương ứng bit thứ 0 -> bit thứ 8
                int val = board[i][j] - '1'; 
                int mask = 1 << val;

                // Tính toán chỉ số sub-box bằng toán số nguyên thuần túy
                int box_idx = (i / 3) * 3 + (j / 3);

                // Kiểm tra xem bit đã được bật ở Row, Col, hay Box chưa bằng phép toán AND (&)
                if ((row_mask[i] & mask) || (col_mask[j] & mask) || (box_mask[box_idx] & mask)) {
                    return false;
                }

                // Bật bit đánh dấu bằng phép toán OR (|)
                row_mask[i] |= mask;
                col_mask[j] |= mask;
                box_mask[box_idx] |= mask;
            }
        }
        return true;
    }
};

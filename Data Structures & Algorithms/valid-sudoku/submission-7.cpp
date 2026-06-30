class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check for row 
        bool row[9][10] = {false};
        bool col[9][10] = {false};
        bool subBox[10][10] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                // check for row
                if (row[i][val] == true) {
                    return false;
                }
                // check for col
                if (col[j][val] == true) {
                    return false;
                }
                // check for sub-box
                int subIndex = 3 * floor(i/3) + floor(j/3) + 1;
                if (subBox[subIndex][val] == true) {
                    return false;
                }
                row[i][val] = true;
                col[j][val] = true;
                subBox[subIndex][val] = true;
            }
        }
        return true;
    }
};

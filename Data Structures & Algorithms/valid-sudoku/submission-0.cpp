class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check for row 
        bool row[9][10];
        for (int i = 0; i < 9; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                if (row[i][val] == true) {
                    return false;
                }
                row[i][val] = true;
            }
        }

        // Check for column
        bool col[9][10];
        for (int i = 0; i < 9; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                if (board[j][i] == '.') continue;
                int val = board[j][i] - '0';
                if (col[i][val] == true) {
                    return false;
                }
                col[i][val] = true;
            }
        }

        // check for sub-box
        for (int i = 0; i <= 6; i = i+3) {
            for (int j = 0; j <= 6; j = j+3) {
                bool isCheck[10] = {false};
                // cout << " i =. " << i << " j =. " << j << endl;
                // cout << "------------------------" << endl;
                for (int r = i; r < i+3; r++) {
                    for (int c = j; c < j+3; c++) {
                        // cout << "r = " << r << " c = " << c << endl;  
                        // cout << "r = " << r << " c = " << c << " board[r][c] = " << board[r][c] << endl; 
                        if(board[r][c] == '.') continue;
                        int val = board[r][c] - '0';
                        if (isCheck[val] == true) {
                            // cout << "r = " << r << " c = " << c << " board[r][c] = " << board[r][c] << endl; 
                            return false;
                        }
                        isCheck[val] = true;
                    }
                }
            }
        }
        return true;
    }
};

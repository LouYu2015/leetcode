class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool occured[9];
        
        // Validate rows
        for (int row = 0; row < 9; row++) {
            memset(occured, 0, sizeof(occured));
            for (int col = 0; col < 9; col++) {
                char content = board[row][col];
                if (content == '.') {
                    continue;
                }
                if (occured[content - '1']) {
                    return false;
                }
                occured[content - '1'] = true;
            }
        }
        
        // Validate colums
        for (int col = 0; col < 9; col++) {
            memset(occured, 0, sizeof(occured));
            for (int row = 0; row < 9; row++) {
                char content = board[row][col];
                if (content == '.') {
                    continue;
                }
                if (occured[content - '1']) {
                    return false;
                }
                occured[content - '1'] = true;
            }
        }
        
        // Validate sub-boxes
        for (int row_offset = 0; row_offset < 9; row_offset += 3) {
            for (int col_offset = 0; col_offset < 9; col_offset += 3) {
                memset(occured, 0, sizeof(occured));
                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        char content = board[row + row_offset][col + col_offset];
                        if (content == '.') {
                            continue;
                        }
                        if (occured[content - '1']) {
                            return false;
                        }
                        occured[content - '1'] = true;
                    }
                }
            }
        }
        
        return true;
    }
};

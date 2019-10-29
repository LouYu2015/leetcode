class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return;
        }
        
        for (int x = 1; x < m; x++) {
            for (int y = 1; y < n; y++) {
                if (matrix[x][y] == 0) {
                    matrix[x][0] = 0;
                    matrix[0][y] = 0;
                }
            }
        }
        
        for (int x = 1; x < m; x++) {
            for (int y = 1; y < n; y++) {
                if (matrix[x][0] == 0 || matrix[0][y] == 0) {
                    matrix[x][y] = 0;
                }
            }
        }
        bool first_row_zero = false;
        bool first_col_zero = false;
        for (int x = 0; x < m; x++) {
            if (matrix[x][0] == 0) {
                first_col_zero = true;
            }
        }
        for (int y = 0; y < n; y++) {
            if (matrix[0][y] == 0) {
                first_row_zero = true;
            }
        }
        if (first_col_zero) {
            for (int x = 0; x < m; x++) {
                matrix[x][0] = 0;
            }
        }
        if (first_row_zero) {
            for (int y = 0; y < n; y++) {
                matrix[0][y] = 0;
            }
        }
    }
};

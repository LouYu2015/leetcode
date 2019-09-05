class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Swap diagnal
        for (int row = 0; row < n; row++) {
            for (int col = row + 1; col < n; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        
        // Swap left right
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n / 2; col++) {
                swap(matrix[row][col], matrix[row][n - 1 - col]);
            }
        }
    }
};

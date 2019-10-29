class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        
        int low_x = 0, high_x = m, mid_x = (low_x + high_x) / 2;
        while (high_x - low_x > 1) {
            if (target >= matrix[mid_x][0]) {
                low_x = mid_x;
            } else {
                high_x = mid_x;
            }
            mid_x = (low_x + high_x) / 2;
        }
        int x = low_x;
        
        int low_y = 0, high_y = n, mid_y = (low_y + high_y) / 2;
        while (high_y - low_y > 1) {
            if (target >= matrix[x][mid_y]) {
                low_y = mid_y;
            } else {
                high_y = mid_y;
            }
            mid_y = (low_y + high_y) / 2;
        }
        int y = low_y;
        
        return matrix[x][y] == target;
    }
};

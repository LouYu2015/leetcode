class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        // Edge case: matrix is empty
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int upper = 0, bottom = m - 1, left = 0, right = n - 1;
        // invariant: area inside matrix[upper..bottom][left..right] needs to be outputed
        while (upper <= bottom && left <= right) {
            // Upper edge
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[upper][i]);
            }
            upper++;
            if (upper > bottom)
                break;
            
            // Right edge
            for (int i = upper; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            if (left > right)
                break;
            
            // Bottom edge
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (upper > bottom)
                break;
            
            // Left edge
            for (int i = bottom; i >= upper; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};

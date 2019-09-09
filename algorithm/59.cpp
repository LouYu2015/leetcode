class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int current = 1;
        // invariant: the area inside result[top..bottom][left..right] needs to be filled,
        //   'current' is the next number to be filled
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                result[top][i] = current++;
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                result[i][right] = current++;
            }
            right--;
            
            if (!(top <= bottom && left <= right)) {
                break;
            }
            
            for (int i = right; i >= left; i--) {
                result[bottom][i] = current++;
            }
            bottom--;
            
            for (int i = bottom; i >= top; i--) {
                result[i][left] = current++;
            }
            left++;
        }
        return result;
    }
};

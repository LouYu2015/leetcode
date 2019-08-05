class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int n = height.size();
        int i = 0, j = n - 1;
        
        // loop invariant: pair of lines containing height[0..i-1] and height[j+1..n-1]
        // won't be more optimal than current result
        while (i < j) {
            result = max(result, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
};

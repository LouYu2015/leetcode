class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = INT_MAX;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (mid * mid <= x) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

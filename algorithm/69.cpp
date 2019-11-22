class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = (x == INT_MAX? INT_MAX : x + 1);
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (mid < INT_MAX / mid && mid * mid <= x) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

class Solution {
public:
    int reverse(int x) {
        int result;
        bool is_negative = x < 0;
        if (x < 0) {
            x = -x;
        }
        while (x != 0) {
            result *= 10;
            if (result < 0) {
                return 0;
            }
            result += x % 10;
            if (result < 0) {
                return 0;
            }
            x /= 10;
        }
        if (result == INT_MIN) {
            return 0;
        }
        return is_negative? -result : result;
    }
};

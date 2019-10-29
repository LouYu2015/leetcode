class Solution {
public:
    int reverse(int x) {
        int result = 0;
        bool is_negative = x < 0;
        if (x == INT_MIN) {
            return 0;
        }
        if (x < 0) {
            x = -x;
        }
        while (x != 0) {
            if (result > (INT_MAX - x%10)/10) {
                return 0;
            }
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        if (result == INT_MIN) {
            return 0;
        }
        return is_negative? -result : result;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int tmp = 0;
        int x2 = x;
        while (x2 > 0) {
            if (tmp > (INT_MAX - x2 % 10) / 10) {
                return false;
            }
            tmp = tmp * 10 + x2 % 10;
            x2 /= 10;
        }
        return tmp == x;
    }
};

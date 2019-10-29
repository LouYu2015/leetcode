class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int tmp = 0;
        int x2 = x;
        while (x2 > 0) {
            tmp = tmp * 10 + x2;
            if (tmp < 0) {
                return false;
            }
            x2 /= 10;
        }
        return tmp == x;
    }
};

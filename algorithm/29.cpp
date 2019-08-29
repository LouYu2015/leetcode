class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -0x80000000 && divisor == -1) {
            return 0x7FFFFFFF;
        } else {
            if (divisor < 0) {
                divisor = -divisor;
                dividend = -dividend;
            }
            
            int result = 0;
            if (dividend >= 0) {
                while (dividend >= divisor) {
                    result++;
                    dividend -= divisor;
                }
            } else {
                while (dividend <= -divisor) {
                    result--;
                    dividend += divisor;
                }
            }
            return result;
        }
    }
};

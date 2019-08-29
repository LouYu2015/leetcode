class Solution {
public:
    int divide(int dividend, int divisor) {
        // if (dividend == -(1<<31) && divisor == -1) {
        //     return (1<<31) - 1;
        // } else {
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
        // }
    }
};

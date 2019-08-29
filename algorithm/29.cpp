class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == (~0x80000000+1) && divisor == -1) {
            return 0x7FFFFFFF;
        } else {
            bool negative = (dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0);
            unsigned u_dividend = dividend > 0? dividend: -(unsigned)dividend;
            unsigned u_divisor = divisor > 0? divisor: -(unsigned)divisor;
            
            int result = 0;
            int current_bit = 1;
            while (0x7FFFFFFF - u_divisor >= u_divisor && u_dividend >= u_divisor) {
                current_bit <<= 1;
                u_divisor <<= 1;
            }

            while (current_bit > 0) {
                if (u_dividend >= u_divisor) {
                    result += current_bit;
                    u_dividend -= u_divisor;
                }
                current_bit >>= 1;
                u_divisor >>= 1;
            }
            return negative? -result: result;
        }
    }
};


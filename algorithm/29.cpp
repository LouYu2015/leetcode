class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special case: dividend is minimum and divisor is -1
        // This is the only case when there is an overflow in result
        if (dividend == (~0x80000000+1) && divisor == -1) {
            return 0x7FFFFFFF;
        } else {
            // Is the result negative?
            bool negative = (dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0);
            // Absolute value of dividend
            unsigned u_dividend = dividend > 0? dividend: -(unsigned)dividend;
            // Absolute value of divisor
            unsigned u_divisor = divisor > 0? divisor: -(unsigned)divisor;

            // Use binary search to find the result

            // Find the upper boundary
            unsigned result = 0;
            unsigned current_bit = 1;
            // invariant: u_divisor = divisor * current_bit
            while (0xFFFFFFFF - u_divisor >= u_divisor) {
                current_bit <<= 1;
                u_divisor <<= 1;
            }

            // invariant: dividend = u_dividend + divisor * result,
            //   u_divisor = divisor * current_bit
            while (current_bit > 0) {
                if (u_dividend >= u_divisor) {
                    result += current_bit;
                    u_dividend -= u_divisor;
                }
                current_bit >>= 1;
                u_divisor >>= 1;
            }

            // Negate the result if needed
            return negative? -result: result;
        }
    }
};


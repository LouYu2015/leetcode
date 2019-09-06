class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        int k = n;
        // invariant: x^n = result * x^k
        while (k > 0) {
            if (k % 2 == 1) {
                result *= x;
                k -= 1;
            } else {
                x *= x;
                k /= 2;
            }
        }
        
        // invariant: x^n = result * x^k
        while (k < 0) {
            if (k % 2 == 0) {
                result /= x;
                k += 1;
            } else {
                x *= x;
                k /= 2;
            }
        }
        return result;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        int k = n;
        // invariant: x^n = result * x^k
        while (k > 0) {
            if (k % 2 == 0) {
                x *= x;
                k /= 2;
            } else {
                result *= x;
                k -= 1;
            }
        }
        
        // invariant: x^n = result * x^k
        while (k < 0) {
            if (k % 2 == 0) {
                x *= x;
                k /= 2;
            } else {
                result /= x;
                k += 1;
            }
        }
        return result;
    }
};

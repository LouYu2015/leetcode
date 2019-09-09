class Solution {
public:
    string getPermutation(int n, int k) {
        // The problem starts counting at 1, but it's better to count from 0
        // Thus, I do a conversion here
        k--;
        
        string result;
        
        int p = 1;
        for (int i = 2; i < n; i++) {
            p *= i;
        }
        // p = (n - 1)!
        
        // used[i] records whether the number i + 1 is used
        vector<char> used(n, false);
        // Invariant: p = i!
        //   getPermutation(n, k) = result + getPermutation(i, k)
        for (int i = n - 1; i >= 0; i--) {
            // Number at this position should be the j^th unused number
            int j = k / p;
            // Find the j^th unused number
            // Invariant: the j^th unused number in used[num .. n - 1] is the number we need
            for (int num = 0; num < n; num++) {
                if (!used[num]) {
                    if (j == 0) {
                        // Found
                        result += num + '1';
                        used[num] = true;
                        break;
                    }
                    j--;
                }
            }
            
            // Keep the invariant
            // Avoid division by zero
            if (i != 0) {
                k = k % p;
                p /= i;
            }
        }
        return result;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        int p = 1;
        for (int i = 2; i < n; i++) {
            p *= i;
        }
        
        vector<char> used(n, false);
        for (int i = n - 1; i >= 0; i--) {
            int j = k / p;
            for (int num = 0; num < n; num++) {
                if (!used[num]) {
                    if (j == 0) {
                        result += num + '0';
                        used[num] = true;
                    }
                    j--;
                }
            }
            if (i != 0) {
                k = k % p;
                p /= i;
            }
        }
        return result;
    }
};

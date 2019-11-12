class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        int n = digits.size();
        result[n-1]++;
        for (int current = n - 1; current >= 0; current--) {
            if (result[current] >= 10) {
                result[current] = 0;
                if (current - 1 >= 0) {
                    result[current - 1]++;
                } else {
                    result.insert(result.begin(), 1);
                }
            }
        }
        return result;
    }
};

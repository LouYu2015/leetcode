class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.length(), b.length());
        int carry = 0;
        vector<char> sum;
        for (int i = 0; i < n; i++) {
            int index_a = a.length() - 1 - i;
            int index_b = b.length() - 1 - i;
            int current_a = index_a >= 0 ? a[index_a] - '0' : 0;
            int current_b = index_b >=0 ? b[index_b] - '0' : 0;
            int result = current_a + current_b + carry;
            carry = result / 2;
            result %= 2;
            sum.push_back(result + '0');
        }
        if (carry != 0) {
            sum.push_back(carry + '0');
        }
        reverse(sum.begin(), sum.end());
        return string(sum);
    }
};

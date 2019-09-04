class Solution {
public:
    string multiply(string num1, string num2) {
        vector<char> a = convertToVector(num1);
        vector<char> b = convertToVector(num2);
        vector<char> result;
        for (int i = 0; i < b.size(); i++) {
            vector<char> k = multiply(a, b[i] - '0');
            shift(k, i);
            result = add(result, k);
        }
        return convertToString(result);
    }
    
    vector<char> convertToVector(string num) {
        vector<char> result(num.begin(), num.end());
        reverse(result.begin(), result.end());
        return result;
    }
    
    string convertToString(vector<char> num) {
        reverse(num.begin(), num.end());
        return string(num.begin(), num.end());
    }
    
    vector<char> add(vector<char> a, vector<char> b) {
        vector<char> result;
        int carry = 0;
        int na = a.size();
        int nb = b.size();
        int n = max(na, nb);
        for (int i = 0; carry > 0 || i < n; i++) {
            int current = carry;
            if (i < na) {
                current += a[i] - '0';
            }
            if (i < nb) {
                current += b[i] - '0';
            }
            result.push_back((current % 10) + '0');
            carry = current / 10;
        }
        return result;
    }
    
    vector<char> multiply(vector<char> a, int k) {
        vector<char> result;
        int carry = 0;
        int n = a.size();
        for (int i = 0; carry > 0 || i < n; i++) {
            int current = carry;
            if (i < n)
                current += (a[i] - '0') * k;
            result.push_back((current % 10) + '0');
            carry = current / 10;
        }
        return result;
    }
    
    void shift(vector<char> &a, int n) {
        for (int i = 0; i < n; i++) {
            a.insert(a.begin(), '0');
        }
    }
};

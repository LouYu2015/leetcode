class Solution {
public:
    string multiply(string num1, string num2) {
        // Convert to vector and reverse digits
        vector<char> a = convertToVector(num1);
        vector<char> b = convertToVector(num2);
        
        // Use column multiplication to multiply
        vector<char> result;
        for (int i = 0; i < b.size(); i++) {
            vector<char> k = multiply(a, b[i]);
            add(result, k);
            shift(a, 1);
        }
        
        // Reverse digits again and convert to string
        return convertToString(result);
    }
    
    // Convert to vector and reverse digits
    vector<char> convertToVector(string &num) {
        // Convert to vector
        vector<char> result(num.begin(), num.end());
        
        // Reverse digits
        reverse(result.begin(), result.end());
        
        // Convert char to int
        for (char &c : result) {
            c -= '0';
        }
        
        return result;
    }
    
    string convertToString(vector<char> &num) {
        // Remove leading zeros
        while (num.size() > 0 && num.back() == 0) {
            num.pop_back();
        }
        
        // Check if it's zero
        if (num.size() == 0) {
            return string("0");
        } else {
            // Reverse digits
            reverse(num.begin(), num.end());
            
            // Convert int to char
            for (char &c : num) {
                c += '0';
            }
            
            // Convert to string
            return string(num.begin(), num.end());
        }
    }
    
    // Add 'b' to 'a'
    void add(vector<char> &a, const vector<char> &b) {
        // Carry-in for current digit
        int carry = 0;
        
        // Length
        int na = a.size();
        int nb = b.size();
        int n = max(na, nb);
        
        for (int i = 0; carry > 0 || i < n; i++) {
            // Include carry-in from last digit
            int current = carry;
            
            // Add first number
            if (i < na) {
                current += a[i];
            }
            
            // Add second number
            if (i < nb) {
                current += b[i];
            }
            
            // Save current digit
            if (i < na) {
                a[i] = current % 10;
            } else {
                a.push_back(current % 10);
            }
            
            // Carry-in for next digit
            carry = current / 10;
        }
    }
    
    // Multiply the number 'a' by 'k'
    vector<char> multiply(const vector<char> &a, int k) {
        // Result digits
        vector<char> result;
        
        // Carry-in for current digit
        int carry = 0;
        
        // Length
        int n = a.size();
        for (int i = 0; carry > 0 || i < n; i++) {
            // Add carry-in from last digit
            int current = carry;
            
            // Multiply
            if (i < n)
                current += a[i] * k;
            
            // Save result
            result.push_back(current % 10);
            
            // Carry-in for next digit
            carry = current / 10;
        }
        return result;
    }
    
    // Shift number 'a' by 'n' digits
    void shift(vector<char> &a, int n) {
        for (int i = 0; i < n; i++) {
            a.insert(a.begin(), 0);
        }
    }
};

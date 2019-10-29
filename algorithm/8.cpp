class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        
        while (iswspace(str[i])) {
            i++;
        }
        
        bool negative;
        switch (str[i]) {
            case '+':
                negative = false;
                i++;
                break;
            case '-':
                negative = true;
                i++;
                break;
            default:
                negative = false;
                break;
        }
        
        int result = 0;
        while (isdigit(str[i])) {
            if (result > INT_MAX / 10) {
                return negative? INT_MIN : INT_MAX;
            }
            
            result *= 10;
            
            if (result > INT_MAX - (str[i] - '0')) {
                return negative? INT_MIN : INT_MAX;
            }
            
            result += str[i] - '0';
            i++;
        }
        
        return negative? -result : result;
    }
};

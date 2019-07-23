class Solution {
public:
    int romanToInt(string s) {
        int result = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            char next = i < n - 1 ? '\0' : s[i+1];
            switch (s[i]) {
                case 'I':
                    switch (s[i+1]) {
                        case 'V':
                        case 'X':
                            result -= 1;
                            break;
                        default:
                            result += 1;
                            break;
                    }
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    switch (s[i+1]) {
                        case 'L':
                        case 'C':
                            result -= 10;
                            break;
                        default:
                            result += 10;
                            break;
                    }
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    switch (s[i+1]) {
                        case 'D':
                        case 'M':
                            result -= 100;
                            break;
                        default:
                            result += 100;
                            break;
                    }
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }
        return result;
    }
};

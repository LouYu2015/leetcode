class Solution {
public:
    string convert(string s, int numRows) {
        int i = 1;
        int j = numRows * 2 - 3;
        int n = s.length();
        char *result = new char[n+1];
        int top = 0;
            
        for (int k = 0; k < n; k += numRows*2-2) {
            result[top] = s[k];
            top++;
        } 
        while (i <= j) {
            for (int a = i, b = j; a < n; a += numRows*2-2, b += numRows*2-2) {
                result[top] = s[a];
                top++;
                if (b < n && i != j) {
                    result[top] = s[b];
                    top++;
                }
            }
            i++;
            j--;
        }
        result[n] = '\0';
        string r(result);
        delete [] result;
        return r;
    }
};

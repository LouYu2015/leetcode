class Solution {
public:
    string convert(string s, int numRows) {
        int i = 1;
        int j = numRows * 2 - 3;
        int n = s.length();
        
        if (numRows == 1) {
            return s;
        }
        
        string result;
            
        for (int k = 0; k < n; k += numRows*2-2) {
            result.append(1, s[k]);
        } 
        while (i <= j) {
            for (int a = i, b = j; a < n; a += numRows*2-2, b += numRows*2-2) {
                result.append(1, s[a]);
                if (b < n && i != j) {
                  result.append(1, s[b]);
                }
            }
            i++;
            j--;
        }
        return result;
    }
};

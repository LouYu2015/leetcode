class Solution {
    public String countAndSay(int n) {
        assert n >= 1;
        
        // Base case
        if (n == 1) {
            return "1";
        }
        
        String prevResult = countAndSay(n - 1);
        char prevChar = '\n';
        int count = 0;
        StringBuffer result = new StringBuffer();
        for (char c : prevResult.toCharArray()) {
            if (c == prevChar) {
                count++;
            } else {
                if (count != 0) {
                    result.append(count);
                    result.append(prevChar);
                }
                count = 1;
            }
            prevChar = c;
        }
        
        result.append(count);
        result.append(prevChar);
        
        return result.toString();
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return restore_helper(s, 0, 4);
    }
    
    vector<string> restore_helper(string &s, int start, int depth) {
        vector<string> result;
        if (depth == 0) {
            if (start == s.length()) {
                result.push_back("");
                return result;
            } else {
                return result;
            }
        }
        
        int current = 0;
        for (int i = 0; i < 3; i++) {
            // Check boundary
            if (start + i >= s.length()) {
                break;
            }
            current = current * 10 + s[start + i] - '0';
            if (current > 255) {
                break;
            }
            vector<string> child_result = restore_helper(s, start + i + 1, depth - 1);
            for (string solution : child_result) {
                if (solution.length() == 0) {
                    result.push_back(s.substr(start, i + 1));
                } else {
                    result.push_back(s.substr(start, i + 1) + "." + solution);
                }
            }
            if (current == 0) {
                break;
            }
        }
        return result;
    }
};

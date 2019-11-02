class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> bracket_pair;
        bracket_pair[')'] = '(';
        bracket_pair['}'] = '{';
        bracket_pair[']'] = '[';
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            } else {
                if (stack.size() == 0 || stack.back() != bracket_pair[c]) {
                    return false;
                }
                stack.pop_back();
            }
        }
        return true;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        assert(num > 0);
        // Map from symbol to value, sorted by priority
        vector<pair<string, int>> symbols;
        symbols.push_back(pair<string, int>(string("M"), 1000));
        symbols.push_back(pair<string, int>(string("CM"), 900));
        symbols.push_back(pair<string, int>(string("D"), 500));
        symbols.push_back(pair<string, int>(string("CD"), 400));
        symbols.push_back(pair<string, int>(string("C"), 100));
        symbols.push_back(pair<string, int>(string("XC"), 90));
        symbols.push_back(pair<string, int>(string("L"), 50));
        symbols.push_back(pair<string, int>(string("XL"), 40));
        symbols.push_back(pair<string, int>(string("X"), 10));
        symbols.push_back(pair<string, int>(string("IX"), 9));
        symbols.push_back(pair<string, int>(string("V"), 5));
        symbols.push_back(pair<string, int>(string("IV"), 4));
        symbols.push_back(pair<string, int>(string("I"), 1));
        
        string result;
        int i = 0;
        while (num > 0) {
            // Find the greatest symbol that can be subtracted
            while (symbols[i].second > num) {
                i++;
            }
            result += symbols[i].first;
            num -= symbols[i].second;
        }
        return result;
    }
};

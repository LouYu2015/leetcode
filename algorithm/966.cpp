class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> dict, cap_dict, vowel_dict;
        for (int i = wordlist.size() - 1; i >= 0; i--) {
            // Original word
            string orig = wordlist[i];
            
            // Process capitalization
            string ncap = orig;
            normalize_cap(ncap);
            
            // Process Vowels
            string nvowel = ncap;
            normalize_vowels(nvowel);
            
            
            // Build index
            cap_dict[ncap] = orig;
            vowel_dict[nvowel] = orig;
            dict[orig] = orig;
        }
        
        
        vector<string> result;
        for (auto s : queries) {
            // Search original
            auto pos = dict.find(s);
            if (pos != dict.end()) {
                result.push_back(pos->second);
                continue;
            }
            
            // Search capitalized
            normalize_cap(s);
            pos = cap_dict.find(s);
            if (pos != cap_dict.end()) {
                result.push_back(pos->second);
                continue;
            }
            
            // Search vowels
            normalize_vowels(s);
            pos = vowel_dict.find(s);
            if (pos != vowel_dict.end()) {
                result.push_back(pos->second);
                continue;
            }
            
            // Not found
            result.push_back("");
        }
        return result;
    }
    
    void normalize_cap(string &s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
        }
    }
    
    void normalize_vowels(string &s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    s[i] = 'a';
                    break;
            }
        }
    }
};

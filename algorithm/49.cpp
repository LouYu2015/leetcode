class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map from sorted anagram to list of anagram
        unordered_map<string, vector<string>> index;
        
        // Insert into index
        for (string &str : strs) {
            // Get index key
            string key(str);
            sort(key.begin(), key.end());
            
            // Create list if needed
            if (index.find(key) == index.end()) {
                index[key] = vector<string>();
            }
            
            // Add to list
            index[key].push_back(str);
        }
        
        // Convert to list
        vector<vector<string>> result;
        for (pair<string, vector<string>> item : index) {
            result.push_back(item.second);
        }
        return result;
    }
};

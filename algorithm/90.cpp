class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        return subsetHelper(count);
    }
    
    vector<vector<int>> subsetHelper(map<int, int> count) {
        vector<vector<int>> result;
        if (count.size() == 0) {
            return result;
        }
        pair<int, int> item = *count.begin();
        int num = item.first;
        int num_count = item.second;
        
        count.remove(num);
        
        result = subsetHelper(count);
        int result_size = result.size();
        for (int n = 1; n <= num_count; n++) {
            for (int i = 0; i < result_size; i++) {
                vector<int> next = result[i];
                for (int k = 0; k < n; k++) {
                    next.push_back(num);
                }
                result.push_back(next);
            }
        }
        return result;
    }
};

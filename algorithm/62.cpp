class Solution {
public:
    int uniquePaths(int m, int n) {
        assert(m > 0);
        assert(n > 0);
        
        // Dynamic programming: f[i][j] means number of unique paths starting from point (i, j)
        //   f[i][j] = f[i+1][j] + f[i][j+1]
        //   Base case: points on bottom and right edges have only one path
        //   Optimize with rolling array
        vector<int> paths(m, 1);
        for (int i = 0; i < n - 1; i++) {
            for (int j = m - 2; j >= 0; j--) {
                paths[j] += paths[j+1];
            }
        }
        return paths[0];
    }
};

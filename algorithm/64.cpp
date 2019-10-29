class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        for (int x = m - 1; x >= 0; x--) {
            for (int y = n - 1; y >= 0; y--) {
                if (x == m - 1 && y != n - 1) {
                    grid[x][y] += grid[x][y+1];
                } else if (y == n - 1 && x != m - 1) {
                    grid[x][y] += grid[x+1][y];
                } else if (x != m - 1 && y != n - 1) {
                    grid[x][y] += min(grid[x+1][y], grid[x][y+1]);
                }
            }
        }
        return grid[0][0];
    }
};

class Solution {
public:
    int directions[][] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) {
            return word.length() == 0;
        }
        int n = board[0].size();
        
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                bool found = search_helper(board, word, 0, x, y);
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search_helper(vector<vector<char>> &board, string &word, int i, int x, int y) {
        if (i == word.length() - 1 && board[x][y] == word[i]) {
            return true;
        }
        char current = board[x][y];
        board[x][y] = '\0';
        for (int i = 0; i < 4; i++) {
            int dx = directions[i][0];
            int dy = directions[i][1];
            int next_x = x + dx;
            int next_y = y + dx;
            if (next_x >= 0 && next_x < board.size() && next_y >= 0 && next_y < board[0].size()
                    && board[next_x][next_y] == word[i]) {
                bool found = search_helper(board, word, i + 1, next_x, next_y);
                if (found) {
                    board[x][y] = current;
                    return true;
                }
            }
        }
        board[x][y] = current;
        return false;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> parent(M.size(), -1);
        
        int n = M.size();
        int count = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] && find(parent, i) != find(parent, j)) {
                    my_union(parent, i, j);
                    count--;
                }
            }
        }
        return count;
    }
    
    int find(vector<int> &parent, int i) {
        if (parent[i] == -1) {
            return i;
        } else {
            parent[i] = find(parent, parent[i]);
            return parent[i];
        }
    }
    
    void my_union(vector<int> &parent, int i, int j) {
        parent[find(parent, i)] = j;
    }
};

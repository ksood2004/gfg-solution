// User function Template for C++

class Solution {
public:
    void dfs(int i, int j, int base_i, int base_j,
             vector<vector<int>>& grid, vector<pair<int, int>>& shape, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1)
            return;

        grid[i][j] = 0;  // mark as visited
        shape.push_back({i - base_i, j - base_j});  // relative position

        dfs(i+1, j, base_i, base_j, grid, shape, n, m);
        dfs(i-1, j, base_i, base_j, grid, shape, n, m);
        dfs(i, j+1, base_i, base_j, grid, shape, n, m);
        dfs(i, j-1, base_i, base_j, grid, shape, n, m);
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<vector<pair<int, int>>> distinctShapes;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, i, j, grid, shape, n, m);
                    distinctShapes.insert(shape);
                }
            }
        }

        return distinctShapes.size();
    }
};

// User function Template for C++

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& adj, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || adj[i][j] != 'O')
            return;

        adj[i][j] = '#';
        dfs(i+1, j, adj, n, m);          
        dfs(i-1, j, adj, n, m);          
        dfs(i, j+1, adj, n, m);          
        dfs(i, j-1, adj, n, m);          
    }

    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n == 0 || m == 0) return mat;

        // Check boundary 'O's
        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 'O') dfs(i, 0, mat, n, m);
            if(mat[i][m-1] == 'O') dfs(i, m-1, mat, n, m);
        }

        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 'O') dfs(0, j, mat, n, m);
            if(mat[n-1][j] == 'O') dfs(n-1, j, mat, n, m);
        }

        // Final conversion
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } else if(mat[i][j] == '#') {
                    mat[i][j] = 'O';
                }
            }
        }

        return mat;
    }
};

class Solution {
  public:
     void dfsHelper(int src, int V, vector<int> &visited, 
                            vector<vector<int>> &adj, vector<int> &dfs) {
        visited[src] = 1;
        dfs.push_back(src);
        for (auto nbr: adj[src]) {
            if (!visited[nbr]) {
                dfsHelper(nbr, V, visited, adj, dfs);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> dfs;
        for (int i = 0; i <V; i++) {
            if (!visited[i]){
                dfsHelper(i, V, visited, adj, dfs);
            }
        }
        return dfs;
    
    }
};
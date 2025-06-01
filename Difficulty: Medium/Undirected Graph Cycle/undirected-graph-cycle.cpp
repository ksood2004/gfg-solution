class Solution {
  public:
    bool bfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = 1;

        while (!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbour : adj[curr]) {
                if (!vis[neighbour]) {
                    vis[neighbour] = 1;
                    q.push({neighbour, curr});  // FIXED: push the correct neighbor and its parent
                }
                else if (neighbour != parent) {
                    // A visited neighbor that is not the parent => cycle
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);

        // Build adjacency list from edges
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Run BFS from each unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(adj, vis, i)) {
                    return true;
                }
            }
        }

        return false;
    }
};

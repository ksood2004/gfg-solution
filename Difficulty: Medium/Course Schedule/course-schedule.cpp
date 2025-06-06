class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis, vector<int>& topo) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                if (!dfs(neighbour, adj, vis, pathvis, topo)) {
                    return false;
                }
            } else if (pathvis[neighbour]) {
                // Cycle detected
                return false;
            }
        }

        pathvis[node] = 0;
        topo.push_back(node);  // add node to topological sort
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u); // edge from v to u (v must come before u)
        }

        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis, pathvis, topo)) {
                    return {}; // Cycle detected, not possible
                }
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list with weights
        vector<vector<pair<int,int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            // If undirected, also add: adj[v].push_back({u, wt});
        }

        // Min-heap: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

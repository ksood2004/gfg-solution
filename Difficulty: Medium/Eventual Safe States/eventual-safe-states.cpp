// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<vector<int>> revGraph(V); // reversed graph
        vector<int> indegree(V, 0);

        // Step 1: Reverse the graph
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                revGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        // Step 2: Kahn’s BFS
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbour : revGraph[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end()); // return sorted safe nodes
        return safeNodes;
    }
};


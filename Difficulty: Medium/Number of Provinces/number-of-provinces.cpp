//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>> &adjList, vector<int> &vis, int node) {
    vis[node] = 1;
    for (auto it : adjList[node]) {
        if (!vis[it]) {
            dfs(adjList, vis, it);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    // Convert adjacency matrix to adjacency list
    vector<vector<int>> adjList(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    // Visited array
    vector<int> vis(V, 0);
    int cnt = 0;

    // Count connected components using DFS
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(adjList, vis, i);
        }
    }

    return cnt;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
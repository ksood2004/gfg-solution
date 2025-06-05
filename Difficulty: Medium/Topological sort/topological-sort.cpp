class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        
        //isme humne list mein convert karna hai 
        for(auto & edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        vector<int> topo;
        
        // yeh 0 degree wala jo hai usko push karna hai 
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if(topo.size() !=V){
            return {};
        }
        return topo;
        
        
        
    }
};
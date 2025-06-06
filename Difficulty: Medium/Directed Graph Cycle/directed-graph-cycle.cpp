class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int>indegree(V,0);
        for(auto& edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        vector<int> topo;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int neighbour: adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        
        return topo.size()!=V;
        
    }
};
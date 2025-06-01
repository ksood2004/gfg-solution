
class Solution {
  public:
  void dfs(int node, vector<vector<int>>& adj,vector<int>& vis,vector<int>& component){
      vis[node]=1;
       component.push_back(node);
      for(int neighbour: adj[node]){
          if(!vis[neighbour]){
              dfs(neighbour,adj,vis,component);
          }
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<int> vis(V,0);
        vector<vector<int>> adj(V);
        vector<vector<int>> components;
        for(int i=0;i<edges.size();i++){ // yeh list hai jo bana rhe hum
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int> component;
            
                dfs(i,adj,vis,component);
                components.push_back(component);
            }
        }
        return components;
        
    }
};

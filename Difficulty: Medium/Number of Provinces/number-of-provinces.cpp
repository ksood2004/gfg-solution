// User function Template for C++

class Solution {
  public:
  void dfs(int node , vector<vector<int>>& adj , vector<int> & visited){
      visited[node]=1;
      for(int neighbours : adj[node]){
          if(!visited[neighbours]){
              dfs(neighbours, adj,visited);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> visited(V,0);
        vector<vector<int>> karan(V);
        int pro=0;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    karan[i].push_back(j);
                    karan[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                pro++;
                dfs(i,karan,visited);
            }
        }
      return pro;  
    }
};
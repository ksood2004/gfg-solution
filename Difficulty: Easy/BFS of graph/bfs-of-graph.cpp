class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int v=adj.size();
        vector<int> vis(v,false);
        vector<int> karan;
        queue<int> q;
        
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            karan.push_back(node);
            
            for(int neighbors: adj[node]){
                if(!vis[neighbors]){
                    vis[neighbors]=true;
                    q.push(neighbors);
                }
            }
        
        }
        return karan;
    }
};
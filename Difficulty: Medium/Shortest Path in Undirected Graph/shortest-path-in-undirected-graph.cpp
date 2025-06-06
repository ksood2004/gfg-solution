class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V=adj.size();
        queue<int>q;
        vector<int> distance(V,-1);
        
        
        distance[src]=0;
        q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(int neighbour: adj[node]){
            if(distance[neighbour]==-1){
            distance[neighbour]=distance[node]+1;
            q.push(neighbour);
        }
        }
        
    }
    return distance;
        
        
    }
};
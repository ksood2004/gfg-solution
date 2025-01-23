//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool directed(vector<vector<int>>& adj,int node,vector<int>& vis){
        queue<pair<int,int>> q;
        q.push({node,-1});
        vis[node]=1;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjacent: adj[node]){
                if(!vis[adjacent]){
                    vis[adjacent]=1;
                    q.push({adjacent,node});
                }
                else if(adjacent!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    public:
    bool isCycle(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int> karan(v,0);
        for(int i=0;i<v;i++){
            if(!karan[i]){
            if(directed(adj,i,karan)){
                return true;
            }
        }
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
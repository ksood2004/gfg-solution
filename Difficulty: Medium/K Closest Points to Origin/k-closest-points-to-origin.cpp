class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>>karan;
        priority_queue<pair<int,pair<int,int>>> pq;
        int n=points.size();
        
        for(int i=0;i<n;i++){
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto point=pq.top().second;
            pq.pop();
            karan.push_back({point.first,point.second});
        }
        return karan;
    }
};
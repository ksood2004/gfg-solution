class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        vector<int> karan;
        karan.insert(karan.end(),a.begin(),a.end());
        karan.insert(karan.end(),b.begin(),b.end());
        sort(karan.begin(),karan.end());
        priority_queue<int> pq;
        int n=karan.size();
        for(int i=0;i<n;i++){
            pq.push(karan[i]);
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        return pq.top();
    }
};
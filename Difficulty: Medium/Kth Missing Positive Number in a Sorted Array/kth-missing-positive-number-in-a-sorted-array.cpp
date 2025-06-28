// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes herei
        int n=arr.size();
        unordered_map<int,int> karan;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            karan[arr[i]]++;
        }
        int missing=0;
        int current=1;
        
        while(missing<k){
            if(karan.find(current)==karan.end()){
                pq.push(current);
                missing++;
            }
            current++;
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
        
    }
};
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        int n=arr.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(pq.size()<k){
                pq.push(arr[i]);
            }
            else if(pq.top()>arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
            
        }
        return pq.top();
        
    }
};
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return arr[0];
        }
        
        int t[n];
        t[0]=arr[0];
        t[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            t[i]=max(t[i-1],t[i-2]+arr[i]);
        }
        return t[n-1];
    }
};
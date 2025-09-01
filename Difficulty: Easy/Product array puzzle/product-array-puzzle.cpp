// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> karan(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            karan[i]=ans;
            ans*=arr[i];
        }
        
        ans=1;
        for(int i=n-1;i>=0;i--){
            karan[i]*=ans;
            ans*=arr[i];
        }
        return karan;
        
    }
};

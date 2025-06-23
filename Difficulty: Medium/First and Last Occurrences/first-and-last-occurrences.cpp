class Solution {
  public:
  int first(vector<int>& arr, int x){
      int n=arr.size();
      int s=0;
      int e=n-1;
      int ans=-1;
      while(s<=e){
          int mid=s+(e-s)/2;
          if(arr[mid]==x){
              ans=mid;
              e=mid-1;
          }
          else if(arr[mid]<x){
              
              s=mid+1;
          }
          else{
              e=mid-1;
          }
      }
      return ans;
      
  }
  int second(vector<int>& arr, int x){
      int n=arr.size();
      int s=0;
      int e=n-1;
      int ans=-1;
      while(s<=e){
          int mid=s+(e-s)/2;
          if(arr[mid]==x){
              ans=mid;
              s=mid+1;
          }
          else if(arr[mid]<x){
              
              s=mid+1;
          }
          else{
              
              e=mid-1;
          }
      }
      return ans;
      
  }
    vector<int> find(vector<int>& arr, int x) {
        vector<int> karan(2);
        karan[0]=first(arr,x);
        karan[1]=second(arr,x);
        return karan;
        
    }
};
class Solution {
  public:
  int fist(vector<int>& arr, int target){
      int s=0;
      int n=arr.size();
      int e=n-1;
      int ans=-1;
      while(s<=e){
          int mid=s+(e-s)/2;
          if(arr[mid]==target){
              ans=mid;
              e=mid-1;
          }
          else if(arr[mid]<target){
              s=mid+1;
          }
          else{
              e=mid-1;
          }
      }
    
      return ans;
  }
   int last(vector<int>& arr, int target){
      int s=0;
      int n=arr.size();
      int e=n-1;
      int ans=-1;
      while(s<=e){
          int mid=s+(e-s)/2;
          if(arr[mid]==target){
              ans=mid;
              s=mid+1;
          }
          else if(arr[mid]<target){
              s=mid+1;
          }
          else{
              e=mid-1;
          }
      }
      return ans;
  }
    int countFreq(vector<int>& arr, int target) {
         int f = fist(arr, target);
        int l = last(arr,target);
        if(l==-1 || f==-1){
            return 0;
        }
        return l - f + 1;
        
    }
};

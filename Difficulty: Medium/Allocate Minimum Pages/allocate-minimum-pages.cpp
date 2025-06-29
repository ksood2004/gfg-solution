class Solution {
  public:
bool pages(vector<int>& arr,int n,int maxpage,int k){
      int page=0;
      int student=1;
    
      for(int i=0;i<n;i++){
          if(arr[i]>maxpage){
              return false;
          }
          else if(page+arr[i]>maxpage){
              student++;
              page=arr[i];
              if(student>k){
                  return false;
              }
          }
          else{
              page+=arr[i];
          }
      }
      return true;
  }
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int ans=-1;
        int s=*max_element(arr.begin(),arr.end());
        int e=sum;
        if (k > n) {
        return -1;
    }
        while(s<=e){
            int mid=s+(e-s)/2;
            if(pages(arr,n,mid,k)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};
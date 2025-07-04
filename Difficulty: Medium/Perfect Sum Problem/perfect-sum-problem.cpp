class Solution {
  public:
  int t[1001][1001];
  int karan(vector<int>& arr,int sum,int n){
      for(int i=0;i<=n;i++){
          for(int j=0;j<=sum;j++){
              if(i==0){
                  t[i][j]=0;
              }
              if(j==0){
                  t[i][j]=1;
              }
          }
      }
      
      for(int i=1;i<=n;i++){
          for(int j=0;j<=sum;j++){
              if(arr[i-1]<=j){
                  t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
              }
              else{
                  t[i][j]=t[i-1][j];
              }
          }
      }
      return t[n][sum];
  }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        memset(t,0,sizeof(t));
        return karan(arr,target,n);
        
    }
};
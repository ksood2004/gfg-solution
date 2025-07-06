class Solution {

  public:
  int t[101][10001];
  vector<int> karan(vector<int>& arr,int n,int sum){
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
          for(int j=1;j<=sum;j++){
              if(arr[i-1]<=j){
                  t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
              }
              else{
                  t[i][j]=t[i-1][j];
              }
          }
      }
       vector<int> karann;
      for(int j=0;j<=sum;j++){
          if(t[n][j]){
              karann.push_back(j);
          }
      }
      return karann;
     
  }
    int minDifference(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int mn=INT_MAX;
        memset(t,0,sizeof(t));
        vector<int> hello=karan(arr,n,sum/2);
        for(int i=0;i<hello.size();i++){
            int subsetsum=hello[i];
            mn=min(mn,sum-2*subsetsum);
        }
        return mn;
    }
};

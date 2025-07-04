class Solution {
  public:
  int t[1001][1001];
  int karan(int w,int n, vector<int>& val,vector<int>&wt){
      for(int i=0;i<=n;i++){
          for(int j=0;j<=w;j++){
              if(i==0 || j==0){
                  t[i][j]=0;
              }
              else if(wt[i-1]<=j){
                  t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
              }
              else{
                  t[i][j]=t[i-1][j];
              }
          }
          
      }
      return t[n][w];
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        memset(t,0,sizeof(t));
        int n=val.size();
        return karan(W,n,val,wt);
        
    }
};
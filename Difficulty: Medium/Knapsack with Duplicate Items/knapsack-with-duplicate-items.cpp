// User function Template for C++

class Solution {
  public:
  int t[1001][1001];
  int karan(int n,int m,vector<int>&val,vector<int>& wt){
      
      for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
              if(i==0 || j==0){
                  t[i][j]=0;
              }
          }
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(wt[i-1]<=j){
                  t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
              }
              else{
                  t[i][j]=t[i-1][j];
              }
          }
      }
      return t[n][m];
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        memset(t,0,sizeof(t));
        return karan(val.size(),capacity,val,wt);
        
    }
};
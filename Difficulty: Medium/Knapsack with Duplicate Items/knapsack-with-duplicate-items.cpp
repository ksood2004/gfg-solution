// User function Template for C++

class Solution {
  public:
  int t[1001][1001];
  int karan(int wtt,int n,vector<int>& val, vector<int>& wt){
      for(int i=0;i<=n;i++){
          for(int j=0;j<=wtt;j++){
              if(i==0 || j==0){
                  t[i][j]=0;
              }
              else if(wt[i-1]<=j){
                  t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
              }
              else{
                  t[i][j]=t[i-1][j];
              }
              
          }
      }
      return t[n][wtt];
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        memset(t,0,sizeof(t));
        return karan(capacity,n,val,wt);
        
    }
};
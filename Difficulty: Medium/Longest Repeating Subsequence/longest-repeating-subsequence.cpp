class Solution {
  public:
  int karan(string &s,int n){
      string b=s;
      int m=b.size();
      int t[n+1][m+1];
      for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
              if(i==0 || j==0){
                  t[i][j]=0;
          }
      }
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(s[i-1]==b[j-1] && i!=j){
                  t[i][j]=1+t[i-1][j-1];
              }
              else{
                  t[i][j]=max(t[i-1][j],t[i][j-1]);
              }
          }
      }
      return t[n][m];
  }
    int LongestRepeatingSubsequence(string &s) {
        int n=s.size();
        return karan(s,n);
        
    }
};
class Solution {
  public:
  int t[1001][1001];
  int karan(string &s1,string &s2,int n,int m){
      for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
              if(i==0 || j==0){
                  t[i][j]=0;
              }
          }
      }
      int maxi=0;
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(s1[i-1]==s2[j-1]){
                  t[i][j]=1+t[i-1][j-1];
                  maxi=max(maxi,t[i][j]);
              }
              else{
                  t[i][j]=0;
              }
                  
          }
      }
      return maxi;
  }
    int longestCommonSubstr(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        memset(t,0,sizeof(t));
        return karan(s1,s2,n,m);
        
    }
};
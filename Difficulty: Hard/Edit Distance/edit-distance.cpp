class Solution {
  public:
    int karan(string &s1,string &s2){
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    t[i][j]=j;
                }
                if(j==0){
                    t[i][j]=i;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else{
                    t[i][j]=1+min({t[i-1][j],t[i][j-1],t[i-1][j-1]});
                }
            }
        }
        return t[n][m];
        
    }
    int editDistance(string& s1, string& s2) {
        return karan(s1,s2);
        
    }
};
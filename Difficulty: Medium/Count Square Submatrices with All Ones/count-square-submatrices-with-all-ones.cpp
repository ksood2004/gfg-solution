// User function Template for C++

class Solution {
  public:
  
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        vector<vector<int>> t(N,vector<int> (M,0));
        int ans=0;
        for(int i=0;i<N;i++){
            t[i][0]=matrix[i][0];
            ans+=t[i][0];
        }
        for(int j=1;j<M;j++){
            t[0][j]=matrix[0][j];
            ans+=t[0][j];
        }
        
        for(int i=1;i<N;i++){
            for(int j=1;j<M;j++){
                if(matrix[i][j]==1){
                    ans+=t[i][j]=1+min({t[i-1][j-1],t[i-1][j],t[i][j-1]});
                    
                }
            }
        }
        
        return ans;
    }
};

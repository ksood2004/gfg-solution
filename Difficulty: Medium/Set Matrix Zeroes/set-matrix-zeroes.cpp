// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
         
        int row=mat.size();
        int col=mat[0].size();
        vector<int> newrow(row,1);
        vector<int> newcol(col,1);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    newrow[i]=0;
                    newcol[j]=0;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(newrow[i]==0 || newcol[j]==0){
                    mat[i][j]=0;
                }
            }
        }
    }
};
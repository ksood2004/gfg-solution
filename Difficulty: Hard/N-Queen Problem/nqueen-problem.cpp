//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
 
class Solution{
public:
// yeh wala function direction ke liye 
bool solve(int row,int col,vector<vector<int>>& board,int n){
    int i,j;
    i=row;
    j=col;
    
    //upward
    while(i>=0 && j>=0 && i<n && j<n ){
        if(board[i][j]==1)
            return false;
        
        i--;
    }
    i=row;
    j=col;
    // downward
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]==1)
            return false;
            i++;
        
    }
    i=row;
    j=col;
    //left
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]==1)
            return false;
        
        j--;
    }
    i=row;
    j=col;
    //right
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]==1)
            return false;
        
        j++;
    }
    i=row;
    j=col;
    // up right digaonal
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]==1)
            return false;
        
        i--;
        j++;
    }
    i=row;
    j=col;
    //up left diagonal
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]==1)
            return false;
        
        i--;
        j--;
    }
    i=row;
    j=col;
    //down right
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]==1)
            return false;
        
        i++;
        j++;
    }
    i=row;
    j=col;
    //down left
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]==1)
            return false;
        
        i++;
        j--;
    }
    return true;
}

void hello(int col,int& n,vector<vector<int>>& board,vector<vector<int>>& ans){
    if(col==n){
        vector<int> karan;
    for(int i = 0; i < board[0].size(); i++) {
                for(int j = 0; j < board.size(); j++) {
                    if (board[j][i] == 1) karan.push_back(j + 1);
                }
            }
        ans.push_back(karan);
        return ;
    }
    
    for(int row=0;row<n;row++){
        if(solve(row,col,board,n))
        {
            board[row][col]=1;
            hello(col+1,n,board,ans);
            board[row][col]=0; // yaha backtracking hai 
            
        }
        
    }

}

    vector<vector<int>> nQueen(int n){
        vector<vector<int>> karan;
        vector<vector<int>> ans(n,vector<int>(n,0));
        hello(0,n,ans,karan);
        return karan;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
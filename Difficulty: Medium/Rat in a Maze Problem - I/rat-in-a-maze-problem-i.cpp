//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void solve(vector<vector<int>> &mat,int n,int row,int col,string &path,vector<string> & karan){
      if(row==n-1 && col==n-1){
          karan.push_back(path); // matlab chuha pauch gya hai 
          return ;
      }
       if(row<0 || col<0 || row>=n || col>=n || mat[row][col]==0 ||mat[row][col]==-1){
            return;
        }
      // upward ke liye
      path.push_back('U');
      mat[row][col]=-1;//isme gya hai dekhte hai kya hota hai
      solve(mat,n,row-1,col,path,karan); // (x-1,y)
      mat[row][col]=1;
      path.pop_back(); // hata do backtrack kar diya hai 
    
      
      // downward ke liye
      path.push_back('D');
      mat[row][col]=-1;//isme gya hai dekhte hai kya hota hai
      solve(mat,n,row+1,col,path,karan); //(x+1,y)
      mat[row][col]=1;
      path.pop_back(); // hata do backtrack kar diya hai 
      
      
      // left move ke liye
      path.push_back('L');
      mat[row][col]=-1;//isme gya hai dekhte hai kya hota hai
      solve(mat,n,row,col-1,path,karan); // col cahnge row same 
      mat[row][col]=1;
      path.pop_back(); // hata do backtrack kar diya hai 
      
      
      // right move ke liye 
      path.push_back('R');
      mat[row][col]=-1;//isme gya hai dekhte hai kya hota hai
      solve(mat,n,row,col+1,path,karan); // col change row saye (x,y+1)
      mat[row][col]=1;
      path.pop_back(); // hata do backtrack kar diya hai 
      
      
  }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> karan;
        string path="";
        int n=mat.size();
        if (mat[0][0] == 1) {
        solve(mat, n, 0, 0, path, karan);
    }
        return karan;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
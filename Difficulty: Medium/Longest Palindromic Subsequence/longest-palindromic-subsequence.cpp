//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int karan(string &s,int n){
      string b=s;
      reverse(b.begin(),b.end());
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
              if(s[i-1]==b[j-1]){
                  t[i][j]=1+t[i-1][j-1];
              }
              else{
                  t[i][j]=max(t[i-1][j],t[i][j-1]);
              }
          }
      }
      return t[n][m];
  }
    int longestPalinSubseq(string &s) {
        int n=s.size();
        return karan(s,n);
    }
};

//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
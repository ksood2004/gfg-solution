//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int karan(string& s1, string& s2,int n,int m){
        int t[n+1][m+1];
        int maxi=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                t[i][j]=0;
            }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]= 1+t[i-1][j-1];
                    maxi=max(maxi,t[i][j]);
        }
        else{
            t[i][j]=0;
            //return karan(s1,s2,n,m-1);
        }
    }
}
        return maxi;
}
    int longestCommonSubstr(string& s1, string& s2) {
         int n=s1.size();
        int m=s2.size();
        return karan(s1,s2,n,m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
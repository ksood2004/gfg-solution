//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int karan(vector<int>& val, vector<int>& wt, int capacity,int n){
      int t[n+1][capacity+1];
      for(int i=0;i<=n;i++){
          for(int j=0;j<=capacity;j++){
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
      return t[n][capacity];
      
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        int t[n+1][capacity+1];
        memset(t,0,sizeof(t));
        return karan(val,wt,capacity,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
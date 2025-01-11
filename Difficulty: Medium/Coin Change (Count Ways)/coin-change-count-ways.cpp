//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int hello(vector<int>& coins, int sum,int n){
      int t[n+1][sum+1];
      for(int i=0;i<=n;i++){
          for(int j=0;j<=sum;j++){
              if(i==0){
                  t[i][j]=0;
              }
              if(j==0){
                  t[i][j]=1;
              }
          }
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=sum;j++){
              if(coins[i-1]<=j){
                  t[i][j]=t[i][j-coins[i-1]] + t[i-1][j];
              }
              else{
                  t[i][j]=t[i-1][j];
              }
          }
      }
      return t[n][sum];
  }
    int count(vector<int>& coins, int sum) {
        int n=coins.size();
        return hello(coins,sum,n);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
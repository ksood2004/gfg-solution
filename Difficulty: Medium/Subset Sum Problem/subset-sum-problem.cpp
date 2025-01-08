//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool t[201][40001];
  bool check(int n,int sum,vector<int>& arr){
      for(int i=0;i<=n;i++){
          for(int j=0;j<=sum;j++){
              if(i==0){
              t[i][j]=false;
          }
          if(j==0){
              t[i][j]=true;
          }
         }
      }
          
          for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            } 
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}
  
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        //memset(t,0,sizeof(t));
        return check(n,target,arr);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
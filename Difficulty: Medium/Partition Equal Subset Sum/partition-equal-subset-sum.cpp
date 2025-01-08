//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool t[201][40001];
  bool karan(int n,int sum,vector<int>& arr){
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

    bool equalPartition(vector<int>& arr) {
         int n = arr.size();
        int summ = 0;

        for (int i = 0; i < n; i++) {
            summ += arr[i];
        }

        if (summ % 2 != 0) {
            return false;
        }

        return karan(n, summ / 2, arr);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
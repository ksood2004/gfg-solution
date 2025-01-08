//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   public:
  int t[1001][1001];
  int check(int n,int sum,vector<int>& arr){
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
          
         for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = t[i - 1][j]+t[i - 1][j - arr[i - 1]] ;
            } 
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}
  
    int perfectSum(vector<int>& arr, int target) {
         int n=arr.size();
        memset(t,0,sizeof(t));
        return check(n,target,arr);
    
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
 
class Solution {
  public:
  int t[1001][1001];
  int karan(vector<int>& arr,int i,int j){
      if(i>=j){
          return 0;
      }
      //int t[i+1][j+1];
      if (t[i][j] != -1) { 
            return t[i][j]; // Return precomputed result if available
        }
      int minn=INT_MAX;
      for(int k=i;k<=j-1;k++){
          int temp=karan(arr,i,k)+karan(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
          minn=min(minn,temp);
      }
      return t[i][j]=minn;
  }
    int matrixMultiplication(vector<int> &arr) {
         for(int i=0;i<=arr.size();i++){
          for(int j=0;j<=arr.size();j++){
              
                  t[i][j]=-1;
              
          }
      }
        return karan(arr,1,arr.size()-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends
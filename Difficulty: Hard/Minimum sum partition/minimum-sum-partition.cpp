//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
  int t[201][200001];
  vector<int> karan(vector<int>& arr,int n,int range){
      int t[n+1][range+1];
      for(int i=0;i<=n;i++){
          for(int j=0;j<=range;j++){
              if(i==0){
                  t[i][j]=0;
              }
              if(j==0){
                  t[i][j]=1;
              }
          }
      }
      
      for(int i=1;i<=n;i++){
          for(int j=1;j<=range;j++){
              if(arr[i-1]<=j){
                  t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
              }
              else{
                  t[i][j]=t[i-1][j];
              }
          }
      }
      vector<int> karann;
      for(int j=0;j<=range;j++){
          if(t[n][j]){
              karann.push_back(j);
          }
      }
      return karann;
  }
    int minDifference(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        //vector<int> karann;
        int minn=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
        }
        vector<int> hello=karan(arr,n,sum/2);
        
        for(int i=0;i<hello.size();i++){
            int subsetSum = hello[i];
    minn = min(minn, sum - 2 * subsetSum);
        }
        return minn;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
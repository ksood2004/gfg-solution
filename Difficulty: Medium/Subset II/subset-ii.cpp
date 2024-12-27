//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  vector<vector<int>> ans;
  void solve(vector<int>& ip,vector<int>& op,int index){
      ans.push_back(op); // output ko insert kar rhe final wala 
      // loop duplicTE ko hatane ke liye use kiya hai 
      for(int i=index;i<ip.size();i++){
          if(i>index && ip[i]==ip[i-1]){
              continue;  // agar same ayega to skip mar diya humne
          }
          
          op.push_back(ip[i]);
          solve(ip,op,i+1);
          op.pop_back();
          
         
          
          
      }
      
  }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<int> karan;
        sort(nums.begin(),nums.end());
        solve(nums,karan,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends
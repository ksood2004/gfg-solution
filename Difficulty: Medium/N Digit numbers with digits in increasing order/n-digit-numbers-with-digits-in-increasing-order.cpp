//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void solve(int idx,int n,int res,vector<int>&ans){
        if(idx==n){
            ans.push_back(res);
            return;
        }
        
        for(int i=0;i<=9;i++){
            int val=res;
            res=res*10+i;
            if((res==0 && n==1) || (val%10) < (res%10)) {
                solve(idx+1,n,res,ans);
            }
            res=res/10;
        }
        
    }
    vector<int> increasingNumbers(int n) {
        // Write Your Code here
        vector<int>ans;
        int res;
        solve(0,n,0,ans);
        return ans;
    }

};
    

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
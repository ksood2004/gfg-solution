//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(string &s,int index,vector<string>& karan){
      if(index==s.size()){
          karan.push_back(s);
          return;
      }
      unordered_set<char> prem;
      for(int i=index;i<s.size();i++){
          if(prem.find(s[i])==prem.end()){// agar same nhi mila toh hi considered krega
              prem.insert(s[i]);
              swap(s[index],s[i]);
              solve(s,index+1,karan);
              swap(s[i],s[index]);
      }
  }}
    vector<string> findPermutation(string &s) {
        vector<string> karan;
        solve(s,0,karan);
        return karan;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
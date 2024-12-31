//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(string ip,string op,vector<string>& karan){
      if(ip.size()==0){
          karan.push_back(op);
          return;
      }
      unordered_set<char> prem;
      for(int i=0;i<ip.size();i++){
          if(prem.find(ip[i])==prem.end()){// agar same nhi mila toh hi considered krega
              prem.insert(ip[i]);
          
          string newip=ip.substr(0,i)+ip.substr(i+1);
          string newop=op+ip[i];
          solve(newip,newop,karan);
      }
  }}
    vector<string> findPermutation(string &s) {
        vector<string> karan;
        solve(s,"",karan);
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
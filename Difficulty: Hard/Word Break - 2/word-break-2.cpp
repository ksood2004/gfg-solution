//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<string> karan;
  unordered_set<string> prem;
  
  void solve(int index,string &s, string k){
      if(index==s.size()){
          karan.push_back(k);
          return;
      }
      string temp="";
      for(int i=index;i<s.size();i++){
          temp+=s[i];
          if(prem.find(temp) != prem.end()){//dictionary mein present hai
            string hello=k;
            if(k.size()>0){
                k+=" ";
          }
          k+=temp;
          solve(i+1,s,k);
          k=hello;
          
      }
      } 
  }
    vector<string> wordBreak(vector<string>& dict, string s) {
       
        for(int i=0;i<dict.size();i++){
            prem.insert(dict[i]);
        }
        string hello="";
        solve(0,s,hello);
        return karan;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> dict;
        string s;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> s) {
            dict.push_back(s);
        }
        cin >> s;
        cin.ignore();
        Solution ob;
        vector<string> ans = ob.wordBreak(dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
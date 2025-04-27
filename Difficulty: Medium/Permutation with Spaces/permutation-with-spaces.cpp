//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
vector<string> ans;
    void solve(string ip,string op){
    if(ip.length()==0){
        ans.push_back(op);
        return ;
    }
    else{
    string op1=op;
    string op2=op;
    op1.push_back(' ');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);

    }
    
}
    vector<string> permutation(string s) {
        
        string op;
        op.push_back(s[0]);
        s.erase(s.begin()+0);

        solve(s,op);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends
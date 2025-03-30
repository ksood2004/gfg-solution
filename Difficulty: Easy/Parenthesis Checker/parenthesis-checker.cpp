//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        int n=s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } 
            else {
                if (st.empty()) {
                    return false;
                }
                char ch = st.top();
                st.pop(); 
                if ((ch == '(' && s[i] != ')') || 
                    (ch == '{' && s[i] != '}') || 
                    (ch == '[' && s[i] != ']')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
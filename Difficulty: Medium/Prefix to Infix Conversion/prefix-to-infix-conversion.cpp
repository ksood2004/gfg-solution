//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        int n=s.size();
        stack<string>stk;
        for(int i=n-1;i>=0;i--){
            if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z') ||(s[i]>='0' && s[i]<='9')){
                string s2="";
                s2+=s[i];
                stk.push(s2);
            }
            else{
                string t1=stk.top();
                stk.pop();
                string t2=stk.top();
                stk.pop();
                string s3='('+t1+s[i]+t2+')';
                stk.push(s3);
            }
        }
        return stk.top();
    }
};





//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
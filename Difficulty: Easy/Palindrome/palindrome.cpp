//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isPalindrome(int n) {
        if(n<0){
            return false;
        }
        int karan=n;
        int ans=0;
        while(n>0){
        int digit=n%10;
        ans=(ans*10)+digit;
        n=n/10;
        }
        
        return karan==ans;
        // Code here.
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        bool ans = ob.isPalindrome(n);
        cout << (ans ? "true" : "false") << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
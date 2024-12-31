//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  void solve(string &s, int index, string &karan,int k) {
        if (k==0 || index>=s.size()) { // Base case: All characters are fixed
            karan=max(karan,s);
            return;
        }
        
        for (int i = index; i < s.size(); i++) {// multiple process ke liye
            if(i==index){
                solve(s,index+1,karan,k);
            }
            if(s[i]>s[index]){
                swap(s[index],s[i]);
                solve(s,index+1,karan,k-1);
                swap(s[index],s[i]);
            }
    }}
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        string karan;
        solve(s,0,karan,k);
        return karan;
    }
};

//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
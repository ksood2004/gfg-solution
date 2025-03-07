//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        int k=pat.length(); // length of the window
        int n=txt.length();
        int i=0;
        int j=0;
        vector<int> patset(26,0);
        for(int i=0;i<k;i++){
            patset[pat[i]-'a']++; // isme humne frequency store kari hai
        }
        int cnt=0;
        vector<int> txtset(26,0);
        while(j<n){
            txtset[txt[j]-'a']++;
    
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(txtset==patset){
                    cnt++;
                }
                
                    txtset[txt[i]-'a']--;
                    i++;
                
                j++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
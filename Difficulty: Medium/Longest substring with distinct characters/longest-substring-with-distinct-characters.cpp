//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int i=0;
        int j=0;
        int n=s.size();
        map<char,int> karan;
        int cnt=0;
        int maxx=0;
        while(j<n){
            karan[s[j]]++;
            
        
                while(karan[s[j]]>1){
                    karan[s[i]]--;
                    
                    if(karan[s[i]]==0){
                        karan.erase(karan[s[i]]);
                    }
                    i++;
                }
            
            maxx=max(maxx,j-i+1);
            j++;
            
        }
        return maxx;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
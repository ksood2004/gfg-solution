//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> lengths(n);
        for (int i = 0; i < n; i++) {
            lengths[i] = i + 1; 
        }

        int t[n + 1][n + 1]; 

        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = 0;
                } else if (lengths[i - 1] <= j) {
                    t[i][j] = max(price[i - 1] + t[i][j - lengths[i - 1]], t[i - 1][j]);
                } else {
                    t[i][j] = t[i - 1][j]; 
                }
            }
        }

        return t[n][n]; 
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
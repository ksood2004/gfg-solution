//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        if(e==1){
            return b;
        }
        if(e==0){
            return 1;
        }
        
         if(e < 0){
            return 1/power(b, -1*e);
        }
        double poww=power(b,e/2);
        if(e%2==0){
            return poww*poww;
        }
        else{
            return b*poww*poww;
        }
    }
};


//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
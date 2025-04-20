//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  const int MOD = 1e9 + 7;
  long long poww(long long s, long long n){
      long long res=1;
      while(n>0){
          if(n%2==1)
              res=(res*s)%MOD;
          
          s=(s*s)%MOD;
          n/=2;
      }
      return res;
  }
    int countGoodNumbers(long long N) {
        long long even=(N+1)/2;
        long long odd=N/2;
        long long res=(poww(5,even)*poww(4,odd))%MOD;
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends
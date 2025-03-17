//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int karan(int mid,int n){
      long long ans=1;
      while(n>0){
          if(n%2==1){
              ans=ans*mid;
              n--;
          }
          else{
              mid=mid*mid;
              n=n/2;
          }
      }
      return ans;
  }
    int nthRoot(int n, int m) {
        int s=1;
        int e=m;
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            int midn=karan(mid,n);
            if(midn==m){
                return mid;
            }
            else if(midn>m){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
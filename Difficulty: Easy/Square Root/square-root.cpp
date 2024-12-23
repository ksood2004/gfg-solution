//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        int s=0;
        int e=n;
        int ans=-1;
        int mid;
        while(s<=e){
            int mid=s+(e-s)/2;
            int m=mid*mid;
            if(n==m){
                return mid;
            }
            else if(m>n){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
                
            }
        }
        return ans;
        
        // Your code goes here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
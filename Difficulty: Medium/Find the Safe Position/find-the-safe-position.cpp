//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int N, int K) {
    deque<int> children;

        // Populate the deque with children
        for (int i = 1; i <= N; ++i) {
            children.push_back(i);
        }

        // Simulate the elimination process
        while (children.size() > 1) {
            // Rotate the deque by K-1 steps
            for (int i = 1; i < K; ++i) {
                children.push_back(children.front());
                children.pop_front();
            }

            // Remove the K-th child
            children.pop_front();
        }

        // The last remaining child is the safe position
        return children.front();
    }



    int safePos(int n, int k) {
       return solve(n,k);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
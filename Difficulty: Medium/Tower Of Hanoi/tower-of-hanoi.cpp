//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // You need to complete this function
void hanoi(int n, int from, int to, int aux){
    if(n==0){
            return ;
        }
    
}
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n==0){
            return 0;
        }
        
        
        return pow(2,n)-1;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T; // testcases
    while (T--) {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.towerOfHanoi(N, 1, 3, 2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
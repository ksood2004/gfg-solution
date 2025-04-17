//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
         int current = 0;
    int next = 0;
    int jump = 0;
    int n = arr.size();

    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    for (int i = 0; i < n - 1; i++) {
        current = max(current, i + arr[i]);

        if (i == next) {
            if (current == next) return -1; // can't move forward
            jump++;
            next = current;
        }
    }

    return jump;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends
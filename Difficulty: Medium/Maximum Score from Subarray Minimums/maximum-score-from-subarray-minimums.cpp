//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
public:
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        
        if (n < 2) return -1; // Edge case: If fewer than 2 elements, return -1

        int maxx = INT_MIN;  // Store maximum sum of adjacent pairs

        for (int i = 0; i < n - 1; i++) {
            int sum = arr[i] + arr[i + 1]; // Sum of adjacent elements
            maxx = max(maxx, sum); // Update max sum if current sum is greater
        }

        return maxx;
    }
};




//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
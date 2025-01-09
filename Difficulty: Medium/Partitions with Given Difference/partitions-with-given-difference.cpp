//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
         int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0); // Total sum of the array

        // If (sum + d) is not divisible by 2, no solution is possible
        if ((sum + d) % 2 != 0) {
            return 0;
        }

        // The target sum we are looking for in one subset
        int target = (sum + d) / 2;

        // If target sum is negative or exceeds the total sum, return 0
        if (target < 0 || target > sum) {
            return 0;
        }

        // dp[i] will be the number of ways to get sum i from the array
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // There's always 1 way to make sum 0: by taking no elements

        // Loop through each element in the array
        for (int num : arr) {
            // Update dp table in reverse order (important to avoid reuse of the same element)
            for (int i = target; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }

        // The result is the number of ways to get the subset sum equal to 'target'
        return dp[target];
    }
    
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
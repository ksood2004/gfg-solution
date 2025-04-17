//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
         int n = arr.size();
    if (n == 0) return 0;

    // Sort both arrays to simulate events in order
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platformsNeeded = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    // Use two pointers to simulate the arrival and departure timeline
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platformsNeeded++;
            i++;
        } else {
            platformsNeeded--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platformsNeeded);
    }

    return maxPlatforms;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
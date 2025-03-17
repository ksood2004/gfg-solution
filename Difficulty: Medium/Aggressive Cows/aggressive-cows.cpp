//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
bool cow(vector<int>& arr, int dis, int k) {
    int n = arr.size();
    int no_count = 1;  
    int e = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - e >= dis) {
            no_count++;
            e = arr[i];
        }
        if (no_count >= k) {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());  // Sort the stalls
    
    int s = 1, e = stalls[n - 1] - stalls[0];
    int ans = 0;  // Store the final answer

    while (s <= e) {  
        int mid = s + (e - s) / 2;
        
        if (cow(stalls, mid, k)) {
            ans = mid;  
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
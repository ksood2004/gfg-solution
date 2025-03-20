//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
bool canAllocate(vector<int>& arr, int n, int maxPages, int k) {
    int students = 1; 
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) {
            return false; // If a single book exceeds maxPages, allocation is impossible
        }

        if (currentPages + arr[i] > maxPages) {
            
            students++;
            currentPages = arr[i];
            if (students > k) {
                return false;
            }
        } else {
            
            currentPages += arr[i];
        }
    }

    return true;
}

// Main function to find the minimum maximum pages
int findPages(vector<int>& arr, int k) {
    int n = arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if (k > n) {
        return -1;
    }
    int start = 0; 
    int end = sum; 
    int result = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (canAllocate(arr, n, mid, k)) {
            result = mid; 
            end = mid - 1; 
        } else {
            start = mid + 1; 
        }
    }

    return result;

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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
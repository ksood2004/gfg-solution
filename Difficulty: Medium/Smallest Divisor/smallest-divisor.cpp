//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
   int small(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += ceil(double(nums[i]) / k);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 1; 
        int e = *max_element(arr.begin(), arr.end());
        int ans = e;

        while (s <= e) {
            int mid=s+(e-s)/2;
            int midn=small(arr,mid);
            if (midn<=k) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return s;
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
        int ans = ob.smallestDivisor(arr, d);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//     int nsel(vector<int> &nums){
//     int n = nums.size();
//         vector<int> prem; 
//         int hello=-1;
//         stack<pair<int,int>> karan;
//         for (int i=0;i<n;i++) {
//             if (karan.empty()) {
//                 prem.push_back(hello);
//             }
//             else if (karan.top().first < nums[i]) {
//                 prem.push_back(karan.top().second);
//             }
        
//             else {
//                 while (!karan.empty() && karan.top().first >= nums[i]) {
//                     karan.pop();
//                 }
//                 if (karan.empty()) {
//                     prem.push_back(-1);
//                 } else {
//                     prem.push_back(karan.top().second);
//                 }
//             }
          
//             karan.push({nums[i],i});
//         }
        
//         return prem;
// }
// int nser(vector<int> &nums){
//     int n = nums.size();
//         vector<int> prem; 
//         int hello=7;
//         stack<pair<int,int>> karan;
//         for (int i=n-1;i>=0;i--) {
//             if (karan.empty()) {
//                 prem.push_back(hello);
//             }
//             else if (karan.top().first < nums[i]) {
//                 prem.push_back(karan.top().second);
//             }
        
//             else {
//                 while (!karan.empty() && karan.top().first >= nums[i]) {
//                     karan.pop();
//                 }
//                 if (karan.empty()) {
//                     prem.push_back(-1);
//                 } else {
//                     prem.push_back(karan.top().second);
//                 }
//             }
          
//             karan.push({nums[i],i});
//         }
//         reverse(prem.begin(),prem.end());
        
//         return prem;
// }

    int getMaxArea(vector<int> &arr) {
         int n = arr.size();
    vector<int> prem;  // To store nearest smaller to left indices
    vector<int> neha;  // To store nearest smaller to right indices
    stack<pair<int, int>> karan;   // Stack for left smaller
    stack<pair<int, int>> aaryan; // Stack for right smaller

    // Code for nearest smaller to left
    for (int i = 0; i < n; i++) {
        while (!karan.empty() && karan.top().first >= arr[i]) {
            karan.pop();
        }
        if (karan.empty()) {
            prem.push_back(-1);
        } else {
            prem.push_back(karan.top().second);
        }
        karan.push({arr[i], i});
    }

    // Code for nearest smaller to right
    for (int i = n - 1; i >= 0; i--) {
        while (!aaryan.empty() && aaryan.top().first >= arr[i]) {
            aaryan.pop();
        }
        if (aaryan.empty()) {
            neha.push_back(n); // Push `n` when no smaller element is found
        } else {
            neha.push_back(aaryan.top().second);
        }
        aaryan.push({arr[i], i});
    }

    reverse(neha.begin(), neha.end()); // Reverse `neha` to align with indices

    // Calculate the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = neha[i] - prem[i] - 1;  // Width of the rectangle
        int area = arr[i] * width;         // Area = height * width
        maxArea = max(maxArea, area);      // Update maximum area
    }

    return maxArea;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    int mah(vector<int>& heights){
    int n = heights.size();
    vector<int> prem;  // To store nearest smaller to left indices
    vector<int> neha;  // To store nearest smaller to right indices
    stack<int> karan;   // Stack for left smaller
    stack<int> aaryan; // Stack for right smaller

    // Code for nearest smaller to left
    for (int i = 0; i < n; i++) {
        while (!karan.empty() && karan.top() <= heights[i]) {
            karan.pop();
        }
        if (karan.empty()) {
            prem.push_back(-1);
        } else {
            prem.push_back(karan.top());
        }
        karan.push(heights[i]);
    }

    // Code for nearest smaller to right
    for (int i = n - 1; i >= 0; i--) {
        while (!aaryan.empty() && aaryan.top() <= heights[i]) {
            aaryan.pop();
        }
        if (aaryan.empty()) {
            neha.push_back(n); // Push `n` when no smaller element is found
        } else {
            neha.push_back(aaryan.top());
        }
        aaryan.push(heights[i]);
    }

    reverse(neha.begin(), neha.end()); 

    int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = neha[i] - prem[i] - 1;  
            int area = heights[i] * width;     
            maxArea = max(maxArea, area);     
        }

        return maxArea;
}


    int trappingWater(vector<int> &arr) {
         int n = arr.size();
        if (n <= 2) return 0;

        vector<int> left(n), right(n);

        left[0] = arr[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], arr[i]);
        }

        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], arr[i]);
        }

        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            totalWater += max(0, min(left[i], right[i]) - arr[i]);
        }

        return totalWater;
    
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.trappingWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
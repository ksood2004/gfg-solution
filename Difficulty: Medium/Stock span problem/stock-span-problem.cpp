//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> prem; 
        stack<pair<int,int>> karan;
       for (int i = 0;i<n;i++) {
        if (karan.empty()) {
            prem.push_back(-1);
        }
        else if (karan.top().first > arr[i]) {
            prem.push_back(karan.top().second);
        }
        else {
            while (!karan.empty() && karan.top().first <= arr[i]) {
                karan.pop();
            }
            if (karan.empty()) {
                prem.push_back(-1);
            } else {
                prem.push_back(karan.top().second);
            }
        }
        karan.push({arr[i], i});
    }

  
    // Calculate distances
    for (int i = 0; i < prem.size(); i++) {
        
            prem[i] = i-prem[i];
        }
    return prem;
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
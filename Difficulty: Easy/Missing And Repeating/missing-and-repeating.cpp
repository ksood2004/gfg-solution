//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> ans(2);// 0 is for repeating nuumber 
        //and 1 is for missing number 


        for (int i=0;i<n;i++) {
            mp[arr[i]]++;
        }

        for (auto it=mp.begin();it!=mp.end();it++) {
            if (it->second > 1) {
                ans[0] = it->first; // Repeating number
                break;
            }
        }

        // Step 3: Find the missing number
        for (int i = 1; i <= n; i++) {
            if (mp.find(i) == mp.end()) { // i is not in the map
                ans[1] = i; // Missing number
                break;
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
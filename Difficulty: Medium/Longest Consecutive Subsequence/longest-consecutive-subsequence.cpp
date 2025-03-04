//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int length=1;
        int karan=1;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])==1){
                length++;
            }
            else if(arr[i]-arr[i-1]==0){
                
            }
            else{
                length=1;
            }
            karan=max(karan,length);
        }
        return karan;
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
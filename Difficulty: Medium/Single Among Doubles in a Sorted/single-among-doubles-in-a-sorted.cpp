//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findOnce(vector<int>& arr) {
         int s=0;
       int e=arr.size()-1;
       while(s<e){
        int mid=s+(e-s)/2;
        if((mid%2==0 && arr[mid]==arr[mid+1])  || (mid%2==1 && arr[mid]==arr[mid-1])){
            s=mid+1;
        }
        else{
            e=mid;
        }
       }
       return arr[s];
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.findOnce(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
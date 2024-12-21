//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
  
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        if(arr.empty()){
            return {-1,-1};
        }
         sort(arr.begin(), arr.end());
        int s=0;
        int e=arr.size()-1;
        int mid;
        int res=-1;
        int ceill=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(arr[mid]==x){
                return {x,x};
            }
            // if(arr[mid]>x){
            //     ceill=arr[mid];
            //     e=mid-1;
                
            // }
            if(arr[mid]<x){
                 res=arr[mid];
                s=mid+1;
            }
            else{
                ceill=arr[mid];
                e=mid-1;
                
            }
            
        }
        return {res,ceill};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends
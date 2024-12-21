//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size();
        int mid;
        int res=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(arr[mid]==k){
                return mid;
            }
            if(arr[mid]>k){
                e=mid-1;
                
            }
            else{
                s=mid+1;
                res=mid;
            }
            
        }
        return res;

        // Your code here
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
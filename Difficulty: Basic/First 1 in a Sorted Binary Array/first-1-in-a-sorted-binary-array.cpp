//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        int n=arr.size();
        int s=0;
        int karan=-1;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==1){
                karan=mid;
                e=mid-1;
            }
           
            else{
                s=mid+1;
               
            }
            
        }
        return karan;
        // Your code goes here
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
        getline(cin, input);
        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.firstIndex(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
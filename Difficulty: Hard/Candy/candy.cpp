//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCandy(vector<int> &arr) {
     int n=arr.size();
        vector<int> karan(n,1); // for left
        vector<int> aaryan(n,1); // for right;
        for(int i=1;i<n;i++){
            if (arr[i] > arr[i - 1]) {
                karan[i] = karan[i - 1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                aaryan[i]=aaryan[i+1]+1;
            }
        }
       int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(karan[i], aaryan[i]);
        }

        return sum;
    }
};



//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr = inputLine();

        Solution obj;
        cout << obj.minCandy(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
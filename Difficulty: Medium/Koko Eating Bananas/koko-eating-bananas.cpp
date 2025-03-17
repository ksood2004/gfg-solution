//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int time(vector<int>& v, int hour){
    int n=v.size();
    long long total_time=0;
    for(int i=0;i<n;i++){
        total_time+=ceil((double)v[i]/(double)hour);
    }
    return total_time;
}
    int kokoEat(vector<int>& arr, int k) {
        long s=1;
        long long high = *max_element(arr.begin(), arr.end());
        long long e=high;
        long long n=arr.size();
        while(s<=e){
            int mid=s+(e-s)/2;
            int midn=time(arr,mid);
            if(midn<=k){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
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

        cout << ob.kokoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
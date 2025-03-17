//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool possible(vector<int>& karan,int days,int m,int k){
      int n=karan.size();
      int cnt=0;
      int bo=0;
      for(int i=0;i<n;i++){
          if(karan[i]<=days){
              cnt++;
          }
          else{
              bo+=(cnt/k);
              cnt=0;
          }
      }
      bo+=(cnt/k);
      return bo>=m;
  }
    int minDaysBloom(int m, int k, vector<int> &arr) {
        int n=arr.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        long long val=m*1LL*k*1LL;
        if(val>n){
            return -1;
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
        int s=mini;
        int e=maxi;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(arr,mid,m,k)){
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
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        getline(cin, str);
        int m = stoi(str);
        getline(cin, str);
        int k = stoi(str);
        Solution obj;
        cout << obj.minDaysBloom(m, k, arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
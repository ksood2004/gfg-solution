//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int first(vector<int>& arr, int x,int n,int start,int end){
        int mid;
        int karan=-1;
        if(start>=end){
            return -1;
        }
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==x){
                karan=mid;
                end=mid-1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        mid=start+(end-start)/2;   
        }
        return karan;
  }
  int second(vector<int>& arr, int x,int n,int start,int end){
        int mid;
        int karan=-1;
        if(start>=end){
            return -1;
        }
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==x){
                karan=mid;
                start=mid+1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        mid=start+(end-start)/2;   
        }
        return karan;
  }
vector<int> find(vector<int>& arr, int x) {
    int c=first(arr,x,arr.size(),0,arr.size()-1);
    int d=second(arr,x,arr.size(),0,arr.size()-1);
    return {c,d};
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
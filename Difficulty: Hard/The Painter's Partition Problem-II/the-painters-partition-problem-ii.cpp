//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
 
     bool isPossible(vector<int>arr,int k,int start,int end,int mid){
      int StudentCount=1;
      int PageSum=0;
      for(int i=0;i<arr.size();i++){
          if(PageSum+arr[i]<=mid){
              PageSum+=arr[i];
          }else{
              StudentCount++;
              if(StudentCount>k||arr[i]>mid){
                  return false;
              }
              PageSum=arr[i];
          }
      }
      return true;
  }
  
    int minTime(vector<int>& arr, int k) {
    
        int start=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int end=sum;
        int ans= -1;
        int mid=start+(end-start)/2;
        
        // if(k>arr.size()){
        //     return ans;
        // }
        
        while(start<=end){
            if(isPossible(arr,k,start,end,mid)){
                ans=mid;
                 end=mid-1;
            
            }else{
            start=mid+1;
            }
             mid=start+(end-start)/2;
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
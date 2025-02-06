//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int pivott(vector<int>& nums,int n){
   
        int s=0;
        int e=n-1;
        int mid;
        while(s<e){
            mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
           
        }
    return s;      
}

  int bs(vector<int>& nums, int target,int s,int e){
    
    
    while(s<=e){
        int mid=s+(e-s)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]>target){
        e=mid-1;
    }
    else{
         s=mid+1;
    }
}
    return -1;
}
    int search(vector<int>& arr, int key) {
        int n=arr.size();
        int pivottt=pivott(arr,n);
        
        // line wise code likhna hai for line 1
        if(key>=arr[pivottt] && key<=arr[n-1]){
            return bs(arr,key,pivottt,n-1);// bade elemnt wali line
        }
        else{
           return bs(arr,key,0,pivottt-1);

        }
        //return piv
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
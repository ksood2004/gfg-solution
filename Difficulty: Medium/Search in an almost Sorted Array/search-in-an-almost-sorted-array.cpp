// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid-1]==target && mid>s){
                return mid-1;
            }
            if(arr[mid+1]==target && e>mid){
                return mid+1;
            }
            if(arr[mid]>target){
                e=mid-2;
            }
            else{
                s=mid+2;
            }
            
        }
        return -1;
    }
};
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int s=0;
        int e=n-1;
        int index;
        if(arr[s]<=arr[e]){
                return s;
            }
        while(s<e){
            
            if(arr[s]<=arr[e]){
                return s;
            }
            int mid=s+(e-s)/2;
            if(arr[mid]>arr[e]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
        
    }
};

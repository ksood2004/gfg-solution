class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid]>=arr[mid+1]){
                e=mid;
            }
            else {
                s=mid+1;
            }
        }
        return s;
    }
};
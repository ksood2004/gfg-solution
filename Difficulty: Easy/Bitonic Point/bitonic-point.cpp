// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int s=0;
        int e=n-1;
        int maxx=0;
        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid]>=arr[mid+1]){
                maxx=arr[mid];
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return maxx;
    }
};
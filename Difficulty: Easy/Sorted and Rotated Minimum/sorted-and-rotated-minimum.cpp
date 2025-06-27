class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int index=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                index=i+1;
                break;
            }
        }
        return arr[index];
    }
};
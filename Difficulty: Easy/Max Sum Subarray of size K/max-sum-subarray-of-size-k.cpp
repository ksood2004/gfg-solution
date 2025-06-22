class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0;
        int j=0;
        int sum=0;
        int maxx=INT_MIN;
        while(j<n){
            sum+=arr[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                maxx=max(maxx,sum);
                sum=sum-arr[i];
                i++;
                j++;
            }
            
            
        }
        return maxx;
    }
};
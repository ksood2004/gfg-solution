class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int s=1;
        int e=*max_element(arr.begin(),arr.end());
        int res=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            long long  karan=0;
            for(int p:arr){
                karan+=ceil((double) p/mid);
            }
                if(karan<=k){
                    res=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
                return res;
    }
};
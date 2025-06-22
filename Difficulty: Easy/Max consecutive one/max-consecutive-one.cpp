class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxx=0;
        int cnt1=0;
        int cnt0=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                cnt1++;
                cnt0=0;
                maxx=max(maxx,cnt1);
            }
            else if(arr[i]==0){
                cnt0++;
                cnt1=0;
                maxx=max(maxx,cnt0);
            }
            
        }
      return maxx;  
    }
};
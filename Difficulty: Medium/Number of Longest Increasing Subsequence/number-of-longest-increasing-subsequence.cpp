class Solution {
  public:
    int numberofLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> t(n,1);
        vector<int> cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(t[j]+1==t[i]){
                        cnt[i]+=cnt[j];
                    }
                }
                maxi=max(maxi,t[i]);
            }
        }
        int total=0;
        for(int i=0;i<n;i++){
            if(maxi==t[i]){
                total+=cnt[i];
            }
        }
        return total;
        
    }
};
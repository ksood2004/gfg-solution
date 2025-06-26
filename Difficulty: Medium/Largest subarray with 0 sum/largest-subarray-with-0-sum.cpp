class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> karan;
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                maxi=i+1;
            }
            else{
                if(karan.find(sum)!=karan.end()){
                    maxi=max(maxi,i-karan[sum]);
                }
                else{
                    karan[sum]=i;
                }
            }
        }
        return maxi;
        
    }
};
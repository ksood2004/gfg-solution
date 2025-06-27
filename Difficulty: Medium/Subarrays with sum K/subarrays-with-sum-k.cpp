// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
         int n=arr.size();
        unordered_map<int,int> karan;
        karan[0]=1;
        int sum=0;
        int cnt=0;
        for(int num: arr){
            sum+=num;
            if(karan.find(sum-k)!=karan.end()){
                
                cnt+=karan[sum-k];
            }
            karan[sum]++;
        }
        return cnt;
    }
};
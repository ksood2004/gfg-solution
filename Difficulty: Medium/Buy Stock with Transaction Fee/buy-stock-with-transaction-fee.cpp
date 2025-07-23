class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int buy=INT_MIN;
        int sell=0;
        for(int i=0;i<n;i++){
            buy=max(buy,sell-arr[i]);
            sell= max(sell,arr[i]+buy-k);
        }
        return sell;
    }
};
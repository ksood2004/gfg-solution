class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int min_price=prices[0];
        vector<int> karan(n,0);
        for(int i=1;i<n;i++){
            min_price=min(min_price,prices[i]);
            karan[i]=max(karan[i-1],prices[i]-min_price);
        }
        int max_price=prices[n-1];
        vector<int> karan1(n,0);
        for(int i=n-2;i>=0;i--){
            max_price=max(max_price,prices[i]);
            karan1[i]=max(karan1[i+1],max_price-prices[i]);
        }
        
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,karan[i]+karan1[i]);
        }
        return mx;
    }
};
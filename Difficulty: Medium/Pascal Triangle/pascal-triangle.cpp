
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        long long int ans=1;
        vector<int> karan;
        karan.push_back(1);
        for(int i=1;i<n;i++){
            ans=ans*(n-i);
            ans=ans/i;
            karan.push_back(ans);
        }
        return karan;
    }
};

class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        int n=greed.size();
        int m=cookie.size();
        
        sort(greed.begin(),greed.end());
        sort(cookie.begin(),cookie.end());
        
        int i=0;
        int j=0;
        int cnt=0;
        
        while(i<n && j<m){
            if(cookie[j]>=greed[i]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};
// User function template for C++

class Solution {
  public:
  int bs(vector<int>& mat,int y){
      int x=upper_bound(mat.begin(),mat.end(),y)-mat.begin();
      return x;
  }
    int median(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        
        
        int s=INT_MAX;
        int e=INT_MIN;
        
        for(int i=0;i<n;i++){
            s=min(s,mat[i][0]);
            e=max(e,mat[i][m-1]);
        }
        int ans=(n*m)/2;
        while(s<=e){
            int mid=s+(e-s)/2;
            
        int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=bs(mat[i],mid);
            }
            
            if(cnt<=ans){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s;
        
    }
};

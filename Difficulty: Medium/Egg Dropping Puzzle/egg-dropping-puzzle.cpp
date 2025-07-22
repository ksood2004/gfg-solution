class Solution {
  public:

    int t[1001][1001];
    int karan(int n,int k){
        if(n==1){
            return k;
        }
        if(k==0 || k==1){
            return k;
        }
        
        int s=0;
        int e=k;
        int min_attempt=INT_MAX;
        int temp=0;
        
        if(t[n][k]!=-1){
            return t[n][k];
        }
        while(s<=e){
            int mid=s+(e-s)/2;
            int with_break=karan(n-1,mid-1);
            int without_break=karan(n,k-mid);
            temp=1+max(with_break,without_break);
            if(with_break<without_break){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            min_attempt=min(min_attempt,temp);
        }
        return t[n][k]=min_attempt;
    }
    int eggDrop(int n, int k) {
        memset(t,-1,sizeof(t));
        return karan(n,k);
        
    }
};
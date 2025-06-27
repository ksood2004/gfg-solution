class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        priority_queue<int>karan;
        int sum=0;
        for(int i=0;i<N;i++){
            karan.push(A[i]);
            if(karan.size()>K2){
                karan.pop();
            }
        }
        karan.pop();
        
        while(karan.size()>K1){
            sum+=karan.top();
            karan.pop();
        }
        return sum;
    }
};
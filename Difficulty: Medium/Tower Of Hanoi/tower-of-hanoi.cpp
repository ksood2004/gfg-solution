class Solution {
  public:
  void hanoi(int n,int from,int to,int aux){
      if(n==0){
            return ;
        }
        
        towerOfHanoi(n-1,from,to,aux);
        towerOfHanoi(n-1,from,aux,to);
  }
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        return pow(2,n)-1;
    }
};
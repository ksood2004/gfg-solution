class Solution {
  public:
  void del(stack<int>& s , int k,int mid){
      if(k==mid){
          s.pop();
          return ;
      }
      int val=s.top();
      s.pop();
      del(s,k+1,mid);
      s.push(val);
  }
    
    void deleteMid(stack<int>& s) {
        if(s.empty()){
            return ;
        }
        int n=s.size();
        int mid=n/2;
        del(s,0,mid);
    }
};
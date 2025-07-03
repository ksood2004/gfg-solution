// User function Template for C++

class Solution {
  public:
  
  void rev(stack<int>& s,int k){
      if(s.size()==0){
          s.push(k);
          return ;
      }
      int val=s.top();
      s.pop();
      rev(s,k);
      s.push(val);
  }
    void Reverse(stack<int> &St) {
        int n=St.size();
       if(n==0 || n==1){
           return ;
       }
       int temp=St.top();
       St.pop();
       Reverse(St);
       rev(St,temp);
    }
};
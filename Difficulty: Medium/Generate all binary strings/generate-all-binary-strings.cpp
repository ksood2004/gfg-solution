class Solution {
  public:
    void f(int n, string op, vector<string> &ans) {
        
        if(op.size()==n){
            ans.push_back(op);
            return;
        }
        f(n,op+'0', ans);
        if(op.empty() || op.back()!='1')
            f(n,op+'1', ans);
    }
    
    vector<string> generateBinaryStrings(int n) {
       vector<string> ans;
       string op="";
        f(n,"", ans);
        return ans;
    }
};

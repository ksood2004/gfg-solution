//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool pali(string& s,int i,int j){
      if(i>=j){
          return true;
      }
      if(s[i] != s[j]){
          return false;
      }
      return pali(s,i+1,j-1);
  }
  bool isP(string &s){
        int i=0;
        int j=s.size()-1;
        
        return pali(s,i,j);
        
    }
  
  
  void hi(string& s,vector<vector<string>>& karan,int index,vector<string>& temp){
      if(index>=s.size()){
          karan.push_back(temp);
          return;
      }
      string hello="";
      for(int i=index;i<s.size();i++){
          hello+=s[i];
          if(isP(hello)){
              temp.push_back(hello);
              hi(s,karan,i+1,temp);
              temp.pop_back();
          }
      }
      return;
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> karan;
        vector<string> prem;
        hi(S,karan,0,prem);
        return karan;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
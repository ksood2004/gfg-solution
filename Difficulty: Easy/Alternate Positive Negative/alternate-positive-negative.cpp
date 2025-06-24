// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> ans,pos,neg;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        
        int i=0;
        int j=0;
        while(i<pos.size() && j<neg.size()){
            ans.push_back(pos[i++]);
           
            ans.push_back(neg[j++]);
            
        }
        
        while(i<pos.size()){
            ans.push_back(pos[i++]);
            
        }
        while(j<neg.size()){
            ans.push_back(neg[j++]);
          
        }
        for(int k=0;k<n;k++){
            arr[k]=ans[k];
        }
    }
};
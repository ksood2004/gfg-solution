class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> karan;
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(s.size()==0){
                karan.push_back(-1);
            }
            else if(s.size()>0 && arr[i]<s.top()){
                karan.push_back(s.top());
            }
            else if(s.size()>0 && arr[i]>=s.top()){
                while(s.size()>0 && arr[i]>=s.top()){
                    s.pop();
                }
                if(s.size()==0){
                    karan.push_back(-1);
                }
                else{
                    karan.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(karan.begin(),karan.end());
        return karan;
    }
};
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n=arr.size();
        vector<int> karan;
        vector<int> aaryan;
        int i=0;
        int j=0;
        while(j<n){
            if(arr[j]<0){
                karan.push_back(arr[j]);
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(karan.size()==0){
                    aaryan.push_back(0);
                }
                else{
                    aaryan.push_back(karan.front());
                }
                
                if(!karan.size()==0 && karan.front()==arr[i]){
                    karan.erase(karan.begin());
                }
                i++;
                j++;
                
            }
        }
        return aaryan;
    }
};
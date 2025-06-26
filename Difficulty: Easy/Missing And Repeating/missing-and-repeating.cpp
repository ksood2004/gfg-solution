class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> karan;
        vector<int> nums(2);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            karan[arr[i]]++;
        }
        
        for(auto& it: karan){
            int num=it.second;
            if(num>1){
                nums[0]=it.first;
            }
        }
        
        for(int i=1;i<=n;i++){
            if(karan.find(i)==karan.end()){
                nums[1]=i;
                break;
            }
            
        }
        return nums;
    }
};
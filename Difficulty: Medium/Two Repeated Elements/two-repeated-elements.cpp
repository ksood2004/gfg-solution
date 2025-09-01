class Solution {
  public:
    vector<int> twoRepeated(vector<int>& arr) {
        // we need to return 2 repeated numbers
        vector<int> karan;
        unordered_map<int,int> mp;

        int n = arr.size();
        for(int i=0;i<=n+2;i++){
            mp[arr[i]]++;
        
            if(mp[arr[i]]>1){
                karan.push_back(arr[i]);
            }
        }
        //reverse(karan.begin(),karan.end());
        return karan;
    }
};

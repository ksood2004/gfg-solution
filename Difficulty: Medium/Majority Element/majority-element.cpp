class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int,int> karan;
        int n=arr.size();
        if(n==1){
            return arr[0];
        }
        if(n==2){
            if(arr[0]==arr[1]){
                return arr[0];
            }
            else{
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            karan[arr[i]]++;
        }
        int maxx=0;
        int ele=-1;
        for(auto& it: karan){
            int num=it.first;
            int freq=it.second;
         
            if(freq>maxx){
                maxx=freq;
                ele=num;
            }

        }
        if (maxx > n / 2) {
            return ele;
        } else {
            return -1;
        }
        
    }
};
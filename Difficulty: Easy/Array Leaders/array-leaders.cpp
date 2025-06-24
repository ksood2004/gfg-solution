

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int maxx=arr[n-1];
        
        vector<int> karan;
        karan.push_back(maxx);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=maxx){
                maxx=arr[i];
                karan.push_back(maxx);
            }
        }
       reverse(karan.begin(),karan.end());
        return  karan;
    }
};
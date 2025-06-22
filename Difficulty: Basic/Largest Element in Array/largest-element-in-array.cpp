class Solution {
  public:
    int largest(vector<int> &arr) {
       
            int maxx=*max_element(arr.begin(),arr.end());
        
        return maxx;
        
    }
};

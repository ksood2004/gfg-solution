// User function template for C++
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int n=arr.size();
        int number=0;
        for(int i=0;i<n;i++){
            number^=arr[i];
        }
        return number;
    }
};
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n=arr.size();
    
        int index=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[index++]=arr[i];
            }
        }
        while(index<n){
            arr[index++]=0;
        }
        
        
    }
};
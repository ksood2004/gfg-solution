class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> karan(n);
        for(int i=0;i<n;i++){
            karan[i]=arr[((i+d)%n)];
        }
        for(int i=0;i<n;i++){
            arr[i]=karan[i];
        }
        
    }
};
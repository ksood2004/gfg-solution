class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int maxx=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])==1){
                cnt++;
            }
            else if(abs(arr[i]-arr[i-1])==0){
                
            }
            else {
                cnt=1;
            }
            maxx=max(maxx,cnt);
        }
        return maxx;
        
    }
};
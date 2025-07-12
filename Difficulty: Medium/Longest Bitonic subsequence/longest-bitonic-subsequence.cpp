class Solution {
  public:
   

  int LongestBitonicSequence(int n, vector<int>& nums) {
     vector<int> inc(n, 1);
      vector<int> dec(n, 1);
      int maxlen = 0;

      // Build LIS
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < i; j++) {
              if (nums[i] > nums[j]) {
                  inc[i] = max(inc[i], inc[j] + 1);
              }
          }
      }

      // Build LDS
      for (int i = n - 1; i >= 0; i--) {
          for (int j = n - 1; j > i; j--) {
              if (nums[i] > nums[j]) {
                  dec[i] = max(dec[i], dec[j] + 1);
              }
          }
      }

      // Find max bitonic length
      for (int i = 0; i < n; i++) {
          if(inc[i]>1 && dec[i]>1){
          maxlen = max(maxlen, inc[i] + dec[i] - 1);
      }
      }

      return maxlen;
  
  }
};

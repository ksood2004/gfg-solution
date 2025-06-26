class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        int xr = 0;
        long cnt = 0;

        for (int i = 0; i < n; i++) {
            xr ^= arr[i];

            if (xr == k)
                cnt++;

            if (freq.find(xr ^ k) != freq.end()) {
                cnt += freq[xr ^ k];
            }

            freq[xr]++;
        }

        return cnt;
    }
};

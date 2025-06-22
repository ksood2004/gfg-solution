class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long int n = arr.size();
        long long int sum = 0;
        
        for (long long int i = 0; i < n; i++) {
            sum += arr[i];
        }

        long long int total = (n + 1) * (n + 2) / 2;
        return total - sum;
    }
};

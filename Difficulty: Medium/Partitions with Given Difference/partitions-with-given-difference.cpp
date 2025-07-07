class Solution {
public:
    int countSubsetsWithSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // There's always one subset (empty) with sum 0
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][target];
    }

    int countPartitions(vector<int>& arr, int d) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        // sum1 = (sum + d)/2 must be integer and valid
        if ((sum + d) % 2 != 0 || (sum + d) < 0) return 0;

        int target = (sum + d) / 2;
        return countSubsetsWithSum(arr, target);
    }
};

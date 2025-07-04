//Back-end complete function Template for C++

class Solution {
  public:
   int karran(vector<int>& cost) {
        int n = cost.size();
        vector<int> t(n + 1); // dp array to store min cost to reach each step
        t[0] = 0;
        t[1] = 0;

        for (int i = 2; i <= n; i++) {
            t[i] = min(t[i - 1] + cost[i - 1], t[i - 2] + cost[i - 2]);
        }

        return t[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        return karran(cost);
    }
};
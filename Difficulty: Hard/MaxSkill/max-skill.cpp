class Solution {
  public:
  int t[301][301];

    int hello(int i, int j, vector<int>& nums) {
        if (i > j) return 0;

        if (t[i][j] != -1) return t[i][j];

        int mx = 0;
        for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] +
                        hello(i, k - 1, nums) +
                        hello(k + 1, j, nums);
            mx = max(mx, coins);
        }

        return t[i][j] = mx;
    }
    int maxSkill(vector<int> &arr) {
       int n=arr.size();
       vector<int> karan;
       karan.reserve(2);
       karan.push_back(1);
       for(int i=0;i<n;i++){
           karan.push_back(arr[i]);
       }
       karan.push_back(1);
       memset(t, -1, sizeof(t));
       return hello(1,n,karan);
        
    }
};
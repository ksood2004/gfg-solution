class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int row = arr.size();
        int col = arr[0].size();
        int maxone = 0;
        int maxrow = -1;  // Use -1 if no row has 1s

        for (int i = 0; i < row; i++) {
            int cnt = 0;  // ✅ Reset count for each row
            for (int j = 0; j < col; j++) {
                if (arr[i][j] == 1) {
                    cnt++;
                }
            }
            if (cnt > maxone) {
                maxone = cnt;    // ✅ Update maxone
                maxrow = i;
            }
        }

        return maxrow;
    }
};

class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> karan;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] < arr[i]) {
                karan.push_back(arr[i + 1]);
            } else {
                karan.push_back(-1);
            }
        }
        karan.push_back(-1); // last element has no right neighbor

        for (int i = 0; i < n; i++) {
            arr[i] = karan[i];
        }
    }
};

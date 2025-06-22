class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            // Remove elements out of this window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all smaller elements as they are useless
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // First k elements processed, start adding to result
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};

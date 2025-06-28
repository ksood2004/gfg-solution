// User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
    int start = 0, end = 0, mid, ans = 0;

    for (int i = 0; i < n; i++) {
        start = max(start, arr[i]); // minimum capacity must be at least the max weight
        end += arr[i];              // max capacity could be sum of all weights
    }

    while (start <= end) {
        mid = start + (end - start) / 2;
        int weight = 0, count = 1;

        for (int i = 0; i < n; i++) {
            weight += arr[i];
            if (weight > mid) {
                count++;
                weight = arr[i];
            }
        }

        if (count <= d) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

};
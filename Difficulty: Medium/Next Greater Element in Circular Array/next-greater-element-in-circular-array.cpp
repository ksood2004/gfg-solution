class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> karan(n, -1);  // Initialize with -1s
        stack<int> s;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= arr[i % n]) {
                s.pop();
            }
            if (i < n) {
                if (!s.empty()) {
                    karan[i] = s.top();
                }
            }
            s.push(arr[i % n]);
        }

        return karan;
    }
};

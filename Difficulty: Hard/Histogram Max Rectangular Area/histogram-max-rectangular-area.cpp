
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int> karan;  // For NSL 
        vector<int> aaryan; // For NSR 
        stack<pair<int, int>> s1;        
        stack<pair<int, int>> s2;

        for (int i = 0; i < n; i++) {
            if (s1.empty()) {
                karan.push_back(-1);
            }
            else if (s1.size() > 0 && s1.top().first < arr[i]) {
                karan.push_back(s1.top().second);
            }
            else if (s1.size() > 0 && s1.top().first >= arr[i]) {
                while (s1.size() > 0 && s1.top().first >= arr[i]) {
                    s1.pop();
                }
                if (s1.size() == 0) {
                    karan.push_back(-1);
                }
                else {
                    karan.push_back(s1.top().second);
                }
            }
            s1.push({arr[i], i});
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s2.empty()) {
                aaryan.push_back(n);
            }
            else if (s2.size() > 0 && s2.top().first < arr[i]) {
                aaryan.push_back(s2.top().second);
            }
            else if (s2.size() > 0 && s2.top().first >= arr[i]) {
                while (s2.size() > 0 && s2.top().first >= arr[i]) {
                    s2.pop();
                }
                if (s2.size() == 0) {
                    aaryan.push_back(n);
                }
                else {
                    aaryan.push_back(s2.top().second);
                }
            }
            s2.push({arr[i], i});
        }
        reverse(aaryan.begin(), aaryan.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = aaryan[i] - karan[i] - 1;
            int curr_area = width * arr[i];
            ans = max(ans, curr_area);
        }

        return ans;
    }
};



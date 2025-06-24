// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> ans, pos, neg;
        int n = arr.size();

        // Separate positives and negatives
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            } else {
                neg.push_back(arr[i]);
            }
        }

        int i = 0, j = 0;

        // Add alternately
        while (i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }

        // Add remaining positives
        while (i < pos.size()) {
            ans.push_back(pos[i++]);
        }

        // Add remaining negatives
        while (j < neg.size()) {
            ans.push_back(neg[j++]);
        }
        for(int k=0;k<n;k++){
            arr[k]=ans[k];
        }
        
    }
};

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        unordered_map<char, int> karan;
        int i = 0, j = 0;
        int maxx = 0;

        while (j < n) {
            karan[s[j]]++;

            // If duplicate character found, shrink window from the left
            while (karan[s[j]] > 1) {
                karan[s[i]]--;
                i++;
            }

            // Update max length of unique substring
            maxx = max(maxx, j - i + 1);
            j++;
        }

        return maxx;
    }
};

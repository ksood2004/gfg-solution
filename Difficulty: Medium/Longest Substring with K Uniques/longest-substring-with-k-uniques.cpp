class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char, int> karan;
        int i = 0, j = 0;
        int maxi = -1; // -1 if no valid substring is found

        while (j < n) {
            karan[s[j]]++;

            if (karan.size() < k) {
                j++;
            }
            else if (karan.size() == k) {
                maxi = max(maxi, j - i + 1);
                j++;
            }
            else {
                while (karan.size() > k) {
                    karan[s[i]]--;
                    if (karan[s[i]] == 0) {
                        karan.erase(s[i]);
                    }
                    i++;
                }
                if (karan.size() == k) {
                    maxi = max(maxi, j - i + 1);
                }
                j++;
            }
        }

        return maxi;
    }
};

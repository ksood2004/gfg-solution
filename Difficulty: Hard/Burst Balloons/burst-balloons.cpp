//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxCoins(int left, int right, vector<int> &arr, int karan[][502]) {
    if (left > right) return 0;

    int maxCoins = 0;
    if (karan[left][right] != -1) {
        return karan[left][right];
    }
    for (int k = left; k <= right; k++) {
        int coins = arr[left - 1] * arr[k] * arr[right + 1];
        int leftCoins = getMaxCoins(left, k - 1, arr, karan);
        int rightCoins = getMaxCoins(k + 1, right, arr, karan);
        maxCoins = max(maxCoins, coins + leftCoins + rightCoins);
    }
    karan[left][right] = maxCoins;
    return maxCoins;
}

int maxCoins(vector<int> &arr) {
    int n = arr.size();
    int karan[502][502];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            karan[i][j] = -1;
        }
    }
    arr.insert(arr.begin(), 1);
    arr.push_back(1);
    return getMaxCoins(1, n, arr, karan);
}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.maxCoins(arr) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
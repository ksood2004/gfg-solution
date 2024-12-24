//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    int mah(vector<int>& heights){
 int n = heights.size();
    vector<int> prem;  // To store nearest smaller to left indices
    vector<int> neha;  // To store nearest smaller to right indices
    stack<pair<int, int>> karan;   // Stack for left smaller
    stack<pair<int, int>> aaryan; // Stack for right smaller

    // Code for nearest smaller to left
    for (int i = 0; i < n; i++) {
        while (!karan.empty() && karan.top().first >= heights[i]) {
            karan.pop();
        }
        if (karan.empty()) {
            prem.push_back(-1);
        } else {
            prem.push_back(karan.top().second);
        }
        karan.push({heights[i], i});
    }

    // Code for nearest smaller to right
    for (int i = n - 1; i >= 0; i--) {
        while (!aaryan.empty() && aaryan.top().first >= heights[i]) {
            aaryan.pop();
        }
        if (aaryan.empty()) {
            neha.push_back(n); // Push `n` when no smaller element is found
        } else {
            neha.push_back(aaryan.top().second);
        }
        aaryan.push({heights[i], i});
    }

    reverse(neha.begin(), neha.end()); 

    int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = neha[i] - prem[i] - 1;  // Width of the rectangle
            int area = heights[i] * width;     // Area = height * width
            maxArea = max(maxArea, area);      // Update maximum area
        }

        return maxArea;
    }

    int maxArea(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> v(cols, 0);  // Initialize histogram vector

        // Convert the first row to the initial histogram
        for (int j = 0; j < cols; j++) {
            v[j] = mat[0][j];
        }

        // Calculate max area for the first row
        int mx = mah(v);

        // Process subsequent rows
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    v[j] = 0;  // Reset column height if current cell is 0
                } else {
                    v[j] += mat[i][j];  // Add height if current cell is 1
                }
            }

            // Calculate max area for the updated histogram
            mx = max(mx, mah(v));
        }

        return mx;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(mat) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
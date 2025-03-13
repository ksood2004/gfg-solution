//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   void swapp(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2) {
        if (nums1[idx1] > nums2[idx2]) {
            swap(nums1[idx1], nums2[idx2]);
        }
    }
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int k = m + n;
        int gap = (k / 2) + (k % 2);

        while (gap > 0) {
            int i = 0;
            int j = i + gap;

            while (j < k) {
                // arr1 and arr1
                if (i < n && j < n) {
                    swapp(a, a, i, j);
                }
                // arr1 and arr2
                else if (i < n && j >= n) {
                    swapp(a, b, i, j - n);
                }
                // arr2 and arr2
                else {
                    swapp(b, b, i - n, j - n);
                }

                i++;
                j++;
            }

            if (gap == 1) {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }

        // Copy sorted nums2 back into nums1
      
    }
};


//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
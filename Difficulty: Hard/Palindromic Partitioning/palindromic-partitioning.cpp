//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int t[1001][1001]; // Memoization table

// Helper function to check if a substring is a palindrome
bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function to calculate minimum cuts
int karan(int i, int j, string &s) {
    if (i >= j || isPalindrome(s, i, j)) {
        return 0; // No cuts needed if the substring is already a palindrome
    }

    if (t[i][j] != -1) {
        return t[i][j]; // Return the memoized result
    }

    int hello = INT_MAX;

    for (int k = i; k < j; k++) {
        // Only partition if the left part is a palindrome
        if (isPalindrome(s, i, k)) {
            int temp = 1 + karan(k + 1, j, s); // 1 cut + recursive call for the right part
            hello = min(hello, temp);
        }
    }

    return t[i][j] = hello; // Store and return the result
}

int palindromicPartition(string &s) {
    memset(t, -1, sizeof(t)); // Initialize memoization table with -1
    return karan(0, s.size() - 1, s);
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> karan={{0,0},{1,0},{2,0}};
        for(int i=0;i<n;i++){
            karan[arr[i]]++;
        }
        int index=0;
        for(int i=0;i<3;i++){
            int freq=karan[i];
            for(int j=0;j<freq;j++){
                arr[index]=i;
                index++;
            }
        }
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
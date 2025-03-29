//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int mah(vector<int> & karan){
      int n=karan.size();
      vector<int> aaryan; // for nsr
      vector<int> c; // for nsl
      stack<int> s1;
      stack<int> s2;
      
      //nsl
      for(int i=0;i<n;i++){
          if(s1.size()==0){
              aaryan.push_back(-1);
          }
          else if(s1.size()>0 && s1.top()<karan[i]){
              aaryan.push_back(s1.top());
          }
          else if(s1.size()>0 && s1.top()>=karan[i]){
              while(s1.size()>0 && s1.top()<karan[i]){
                  s1.pop();
              }
              if(s1.size()==0){
                  aaryan.push_back(-1);
              }
              else{
                  aaryan.push_back(s1.top());
              }
          }
          s1.push(karan[i]);
      }
      // nsr
      for(int i=n-1;i>=0;i--){
           if(s2.size()==0){
              aaryan.push_back(-1);
          }
          else if(s2.size()>0 && s2.top()<karan[i]){
              c.push_back(s1.top());
          }
          else if(s2.size()>0 && s2.top()>=karan[i]){
              while(s2.size()>0 && s1.top()<karan[i]){
                  s2.pop();
              }
              if(s2.size()==0){
                  c.push_back(-1);
              }
              else{
                  c.push_back(s2.top());
              }
          }
          s2.push(karan[i]);
      }
      reverse(c.begin(),c.end());
      
      int ans=0;
      for(int i=0;i<n;i++){
          int maxx=c[i]-aaryan[i]-1;
          int area=maxx*karan[i];
          ans=max(area,ans);
      }
      return ans;
  }
    int maxWater(vector<int> &arr) {
         int n = arr.size();
        if (n <= 2) return 0;

        vector<int> left(n), right(n);

        left[0] = arr[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], arr[i]);
        }

        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], arr[i]);
        }

        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            totalWater += max(0, min(left[i], right[i]) - arr[i]);
        }

        return totalWater;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        stack<pair<int,int>> s;
        vector<int>karan;
        for(int i=0;i<n;i++){
            if(s.empty()){
                karan.push_back(-1);
            }
            else if(s.size()>0 && s.top().first>arr[i]){
                karan.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first<=arr[i]){
                while(s.size()>0 && s.top().first<=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    karan.push_back(-1);
                }
                else{
                    karan.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        for(int i=0;i<n;i++){
            karan[i]=i-karan[i];
        }
        return karan;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
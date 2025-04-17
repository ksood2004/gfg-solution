//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int maxMeetings(vector<int>& start, vector<int>& end) {
       int n=end.size();
        int count=0;
        vector<pair<int,int>> karan;
        for(int i=0;i<n;i++){
            karan.push_back({end[i],start[i]});
        }
        sort(karan.begin(),karan.end());
        int endd=-1;
        for(int i=0;i<n;i++){
            if(endd==-1 || karan[i].second>endd){
                count++;
                endd=karan[i].first;
            }
            
        }
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
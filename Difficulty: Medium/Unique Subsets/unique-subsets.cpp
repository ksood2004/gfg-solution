//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
public:
vector<vector<int>> ans;
    void solve(vector<int>& a, vector<int>& op, int index) {
    ans.push_back(op);

    for (int i = index; i < a.size(); i++) {
        // Skip duplicates
        if (i > index && a[i] == a[i-1]) continue;

        // Include a[i] in the current subset
        op.push_back(a[i]);

        // Recur with the next index
        solve(a, op, i + 1);

        // Backtrack by removing the last element
        op.pop_back();
    }
}
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
    vector<int> op;
    sort(arr.begin(), arr.end());
    solve(arr, op, 0);
    return ans;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    
cout << "~" << "\n";
}
}   



// } Driver Code Ends
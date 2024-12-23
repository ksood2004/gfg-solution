//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        
        vector<int> prem; 
        stack<int> karan;
        for (int i =0;i<n;i++) {
            if (karan.empty()) {
                prem.push_back(-1);
            }
            else if (karan.top() < a[i]) {
                prem.push_back(karan.top());
            }
        
            else {
                while (!karan.empty() && karan.top() >= a[i]) {
                    karan.pop();
                }
                if (karan.empty()) {
                    prem.push_back(-1);
                } else {
                    prem.push_back(karan.top());
                }
            }
          
            karan.push(a[i]);
        }
        
        return prem;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
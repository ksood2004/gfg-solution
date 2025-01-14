//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    
    bool isSubSequence(string A, string B) 
    {
        int n = A.size(), m = B.size();
        int i = 0, j = 0;

        // Use two pointers to traverse both strings
        while (i < n && j < m) {
            if (A[i] == B[j]) {
                i++; 
            }
            j++; 
        }


        return i == n;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(int one,int zero,int n,vector<string>& karan,string op){
    if(n==0){
        karan.push_back(op);
        return;
    }
   
    solve(one+1,zero,n-1,karan,op+'1');// pehla character 1 hi hoga kyuki
    if(one>zero){
        solve(one,zero+1,n-1,karan,op+'0');
    }
}
	vector<string> NBitBinary(int n)
	{
	    vector<string>karan;
	    int a=n;
	    int b=n;
	    solve(0,0,n,karan,"");
	    return karan;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends
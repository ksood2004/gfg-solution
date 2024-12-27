//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(string ip,string op,vector<string>& result){
	    if(ip.length()==0){
	        result.push_back(op);
	        return;
	    }
	    string op1=op;
	    string op2=op;
	    op2.push_back(ip[0]);
	    ip.erase(ip.begin()+0);
	    sort(op.begin(),op.end());
	    solve(ip,op1,result);
	    solve(ip,op2,result);
	    return ;
	}
		vector<string> AllPossibleStrings(string s){
		    
		    vector<string> result;
		    
		    solve(s,"",result);
		     sort(result.begin(), result.end());
             return result;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
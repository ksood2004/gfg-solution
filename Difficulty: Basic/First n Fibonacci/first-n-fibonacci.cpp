//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        
        if(n==1){
            return {1} ;
        }
        if(n==2){
            return {1,1};
            }
        vector<long long> k = printFibb(n - 1);
    k.push_back(k[k.size() - 1] + k[k.size() - 2]);

    return k;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends
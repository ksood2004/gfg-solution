//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void deletee(stack<int>& s,int karan,int mid){
        if(karan==mid){
            s.pop();
            return;
        }
        int hello=s.top();
        s.pop();
        
        
        deletee(s,karan+1,mid);
        s.push(hello);
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        if(s.size()==0 || s.size()==1){
            s.pop();
            return;
        }
       int mid=(s.size())/2;
       
       deletee(s,0,mid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        stack<int> s;
        int num;
        while (ss >> num) {
            s.push(num);
        }

        Solution ob;
        ob.deleteMid(s);
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
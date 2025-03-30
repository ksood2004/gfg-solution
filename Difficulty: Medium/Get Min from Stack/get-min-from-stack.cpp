//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    Solution() {
        // code here
    }
    int minn=0;
    stack<int> s;
    void push(int x) {
        if(s.size()==0){
            s.push(x);
            minn=x;
        }
        else{
            if(x>=minn){
                s.push(x);
            }
            else if(x<minn){
                s.push(2*x-minn);
                minn=x;
            }
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if(s.size()==0){
            return ;
        }
        else{
            if(s.top()>=minn){
                s.pop();
            }
            else if(s.top()<minn){
                minn=2*minn-s.top();
                s.pop();
            }
        }
    }

    // Returns top element of the Stack
    int peek() {
        if(s.size()==0){
            return -1;
        }
        if(s.top()>=minn){
            return s.top();
        }
        else if(s.top()<minn){
            return minn;
        }
    }

    // Finds minimum element of Stack
    int getMin() {
        if(s.size()==0){
            return -1;
        }
        return minn;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
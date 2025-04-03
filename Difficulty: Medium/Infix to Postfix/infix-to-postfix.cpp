//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return precedence of operators:
    int precedence(char ch)
    {
        if (ch == '^')
            return 3;
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return -1;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        stack<char> stk;
        string result;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            // If the scanned character is an operand, add it to output string:
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
                result.push_back(ch);
            // If the scanned character is an ‘(‘, push it to the stack:
            else if (ch == '(')
                stk.push(ch);
            // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered:
            else if (ch == ')')
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    result.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            // If an operator is scanned:
            else
            {
                while (!stk.empty() && precedence(ch) <= precedence(stk.top()))
                {
                    result.push_back(stk.top());
                    stk.pop();
                }
                stk.push(ch);
            }
        }
        // Pop all the remaining elements from the stack:
        while (!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};



//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
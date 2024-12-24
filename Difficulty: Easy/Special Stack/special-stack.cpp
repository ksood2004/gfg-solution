//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends


void push(stack<int>& s, int a){
	s.push(a);
	
}

bool isFull(stack<int>& s,int n){
    if( s.size()==n){
        return true;
    }
    else{
        return false;
    }
	
}

bool isEmpty(stack<int>& s){
	if(s.size()==0){
	    return true;
	}
	else{
	    return false;
	}
	
}

int pop(stack<int>& s){
	int x=s.top();
	s.pop();
	return x;
}


int getMin(stack<int>& s) {
    
    int mini = s.top();
     // Create a temporary copy of the stack
    while (!s.empty()) {
        mini = min(mini, s.top());
       s.pop();
    }
    return mini;
}
// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
         int n=arr.size();
         Node* head=new Node(arr[0]);
         Node* temp=head;
         for(int i=1;i<n;i++){
             
             Node* mover=new Node(arr[i]);
             temp->next=mover;
             temp=mover;
         }
         return head;
    }
};
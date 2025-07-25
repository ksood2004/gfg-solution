/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
        if(head==NULL){
            return NULL;
        }
        while(head!=NULL){
            if(head->data==key){
                return true;
            }
            head=head->next;
        }
        return false;
    }
};

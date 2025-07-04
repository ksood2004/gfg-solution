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
    int getCount(struct Node* head) {

        int cnt=0;
        if(head==NULL){
            return NULL;
        }
        
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
};
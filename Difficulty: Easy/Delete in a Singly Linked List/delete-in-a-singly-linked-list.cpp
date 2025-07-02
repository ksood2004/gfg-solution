/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        if(head==NULL){
            return NULL;
        }
        int cnt=1;
        
        if(x==1){
            Node* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        Node* temp=head;
        Node* prev=head;
        while(temp!=NULL){
            if(cnt==x){
                prev->next=prev->next->next;
                delete temp;
                //prev=temp;
            }
            cnt++;
            prev=temp;
            temp=temp->next;
            
        }
        return head;
        
    }
};
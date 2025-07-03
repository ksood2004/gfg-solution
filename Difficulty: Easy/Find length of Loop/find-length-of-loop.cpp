/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    int ll(Node* slow,Node* fast){
        
        int cnt=1;
        fast=fast->next;
     
        while(fast!=slow){
            fast=fast->next;
            cnt++;
        }
        return cnt++;
        
        
    }
    int countNodesinLoop(Node *head) {
        if(head==NULL){
            return NULL;
        }
         Node* slow=head;
        Node* fast=head;
        //int cnt=0;
        // yeh function loop ka hai 
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return ll(slow,fast);
            }
        }
        return 0;
        
    }
};
class Solution {
  public:
    int compare(Node *head1, Node *head2) {
        while(head1 and head2 and (head1->data == head2->data)){
            head1 = head1->next ; 
            head2 = head2->next ; 
        }
        if(!head1 and !head2){
            return 0 ; 
        }
        if(head1 and !head2){
            return 1 ;
        }
        if(!head1 and head2){
            return -1 ; 
        }
        if(head1->data < head2->data){
            return -1; 
        }
        
        return 1 ; 
        
    }
};
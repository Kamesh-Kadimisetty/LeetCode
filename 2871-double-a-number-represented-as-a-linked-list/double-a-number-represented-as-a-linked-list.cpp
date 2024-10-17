class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        ListNode* temp=reverse(head);
        ListNode* curr=temp;
        ListNode* prev=NULL;
        while(curr!=NULL){
            int ans=(curr->val*2)+carry;
            curr->val=(ans)%10;
            if(ans>9){
                carry=1;
            }
            else{
                carry=0;
            }
            prev=curr;
            curr=curr->next;
        }
        if(carry!=0){
                ListNode* dummy=new ListNode(carry);
                prev->next=dummy;
        }
        return reverse(temp);
    }
};
class Solution {
public:
    ListNode* reverselist(ListNode* head){
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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=NULL;
        ListNode* secondhalf=reverselist(slow);
        fast=head;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(secondhalf!=NULL && fast!=NULL){
            temp->next=fast;
            temp=temp->next;
            fast=fast->next;

            temp->next=secondhalf;
            temp=temp->next;
            secondhalf=secondhalf->next;
        }
    }
};
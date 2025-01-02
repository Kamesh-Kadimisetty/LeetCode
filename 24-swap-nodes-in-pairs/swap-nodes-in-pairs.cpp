class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* t1=head;
        ListNode* t2=head->next;
        t1->next=t2->next;
        t2->next=t1;
        head=t2;
        while(t1->next!=NULL && t1->next->next!=NULL){
            ListNode* temp1=t1->next;
            ListNode* temp2 =t1->next->next;

            t1->next=temp2;
            temp1->next=temp2->next;
            temp2->next=temp1;

            t1=temp1;
        }
        return head;
    }
};
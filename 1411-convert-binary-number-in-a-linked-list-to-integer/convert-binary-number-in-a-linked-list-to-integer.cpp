class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result=0;
        ListNode* temp=head;
        while(temp!=NULL){
            result*=2;
            result+=temp->val;
            temp=temp->next;
        }
        return result;
    }
};
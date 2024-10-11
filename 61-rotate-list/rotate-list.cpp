class Solution {
public:
    ListNode* findnthnode(ListNode* temp,int x){
        x--;
        while(temp!=NULL && x>0){
            temp=temp->next;
            x--;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        ListNode* newnode=findnthnode(head,len-k);
        head=newnode->next;
        newnode->next=NULL;
        return head;
    }
};
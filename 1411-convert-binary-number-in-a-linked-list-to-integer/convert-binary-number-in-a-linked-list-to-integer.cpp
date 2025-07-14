class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int result=0,power=0;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]==1){
                result+=pow(2,power);
            }
            power++;
        }
        return result;
    }
};
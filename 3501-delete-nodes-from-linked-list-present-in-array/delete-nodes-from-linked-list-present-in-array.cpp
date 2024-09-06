/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for(auto it:nums){
            s.insert(it);
        }
        ListNode *newhead=new ListNode(-1);
        ListNode *temp=newhead;
        while(head){
            if(s.count(head->val)==0){
                newhead->next=new ListNode(head->val);
                newhead=newhead->next;
            }
            head=head->next;
        }
        return temp->next;
    }
};
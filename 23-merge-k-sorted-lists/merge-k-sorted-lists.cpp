class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pqq;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pqq.push({lists[i]->val,lists[i]});
            }
        }
        while(!pqq.empty()){
            auto it=pqq.top();
            pqq.pop();
           if(it.second->next){
                pqq.push({it.second->next->val,it.second->next});   
            }
            temp->next=it.second;
            temp=temp->next;
        }
        return dummy->next;
    }
};
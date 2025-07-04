class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        queue<TreeNode*>qu;
        TreeNode* target;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr=qu.front();
            qu.pop();
            if(curr->val==start) target=curr;
            if(curr->left){
                mpp[curr->left]=curr;
                qu.push(curr->left);
            }
            if(curr->right){
                mpp[curr->right]=curr;
                qu.push(curr->right);
            }
        }
        queue<pair<TreeNode*,int>>pq;
        pq.push({target,0});
        unordered_set<TreeNode*>st;
        st.insert(target);
        int maxtime=0;
        while(!pq.empty()){
            TreeNode* curr=pq.front().first;
            int time=pq.front().second;
            pq.pop();
            maxtime=max(maxtime,time);
            if(mpp.find(curr)!=mpp.end() && st.find(mpp[curr])==st.end()){
                pq.push({mpp[curr],time+1});
                st.insert(mpp[curr]);
            }
            if(curr->left && st.find(curr->left)==st.end()){
                pq.push({curr->left,time+1}); 
                st.insert(curr->left);             
            }
            if(curr->right && st.find(curr->right)==st.end()){
                pq.push({curr->right,time+1});     
                st.insert(curr->right);         
            }
        }
        return maxtime;
    }
};
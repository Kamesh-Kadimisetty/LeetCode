class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr=qu.front();
            qu.pop();
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
        vector<int>result;
        while(!pq.empty()){
            TreeNode* curr=pq.front().first;
            int level=pq.front().second;
            pq.pop();
            if(level==k) result.push_back(curr->val); 
            if(level>k) break;
            if(mpp.find(curr)!=mpp.end() && st.find(mpp[curr])==st.end()){
                pq.push({mpp[curr],level+1});
                st.insert(mpp[curr]);
            }
            if(curr->left && st.find(curr->left)==st.end()){
                pq.push({curr->left,level+1}); 
                st.insert(curr->left);             
            }
            if(curr->right && st.find(curr->right)==st.end()){
                pq.push({curr->right,level+1});     
                st.insert(curr->right);         
            }
        }
        return result;
    }
};
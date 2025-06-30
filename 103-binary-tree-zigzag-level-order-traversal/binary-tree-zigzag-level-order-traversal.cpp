class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>>result;
        int j=0;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            vector<int>ans;
            for(int i=0;i<n;i++){
                TreeNode* curr=qu.front();
                qu.pop();
                ans.push_back(curr->val);
                if(curr->left!=NULL) qu.push(curr->left);
                if(curr->right!=NULL) qu.push(curr->right);
            }
            if(j%2==1){
                reverse(ans.begin(),ans.end());
            }
            result.push_back(ans);
            j++;
        }
        return result;
    }
};
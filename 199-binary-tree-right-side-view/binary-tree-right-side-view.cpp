class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>qu;
        vector<int>result;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=qu.front();
                qu.pop();
                if(i==n-1) result.push_back(curr->val);
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
        }
        return result;
    }
};
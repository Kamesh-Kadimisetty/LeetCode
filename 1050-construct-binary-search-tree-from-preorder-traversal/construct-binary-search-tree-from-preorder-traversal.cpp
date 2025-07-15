class Solution {
public:
    TreeNode* func(int& ind,vector<int>&preorder,int limit){
        if(ind==preorder.size() || preorder[ind]>limit) return NULL;
        TreeNode* root=new TreeNode(preorder[ind++]);
        root->left=func(ind,preorder,root->val);
        root->right=func(ind,preorder,limit);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return func(ind,preorder,INT_MAX);
    }
};
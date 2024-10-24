class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        TreeNode* leftchild=root->left;
        TreeNode* rightchild=root->right;
        root->right=leftchild;
        root->left=rightchild;
        invertTree(leftchild);
        invertTree(rightchild);
        return root;
    }
};
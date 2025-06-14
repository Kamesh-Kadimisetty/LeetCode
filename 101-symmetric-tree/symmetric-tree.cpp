class Solution {
public:
    bool func(TreeNode* l,TreeNode* r){
        if(l==NULL || r==NULL) return l==r;
        if(l->val!=r->val) return false;
        return func(l->left,r->right) && func(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return func(root->left,root->right);
    }
};
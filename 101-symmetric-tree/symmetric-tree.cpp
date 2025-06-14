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
    
    bool isSameTree(TreeNode* p,TreeNode* q) {
        if (p==nullptr && q==nullptr) {
            return true;
        }
        if (p==nullptr || q==nullptr) {
            return false;
        }
        return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        TreeNode* x=invertTree(root->left);
        return isSameTree(root->right,x);
    }
};
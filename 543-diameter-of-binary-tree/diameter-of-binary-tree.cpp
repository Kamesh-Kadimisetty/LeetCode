class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int depth=maxDepth(root->left)+maxDepth(root->right);
        return max({depth,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
    }
};
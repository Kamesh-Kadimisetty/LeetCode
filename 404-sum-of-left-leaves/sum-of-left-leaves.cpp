class Solution {
public:
    int result=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root!=NULL){
            if(root->left!=NULL &&
               root->left->left==NULL && root->left->right==NULL){
                result+=root->left->val;
            }
            sumOfLeftLeaves(root->left);
            sumOfLeftLeaves(root->right);
        }
        return result;
    }
};
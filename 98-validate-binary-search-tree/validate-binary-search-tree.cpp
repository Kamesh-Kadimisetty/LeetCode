class Solution {
public:
    bool inorder(TreeNode* root,long long& prev){
        if(root!=NULL){
            if(inorder(root->left,prev)==false){
                return false;
            }
            if(root->val<=prev) return false;
            prev=root->val;
            if(inorder(root->right,prev)==false){
                return false;
            }
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        long long prev=LLONG_MIN;
        return inorder(root,prev);
    }
};
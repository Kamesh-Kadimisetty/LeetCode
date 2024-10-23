class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        TreeNode* rightchild=root->right;
        TreeNode* lastright=findlastright(root->left);
        lastright->right=rightchild;
        return root->left;
    }
    TreeNode* findlastright(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            return helper(root);
        }
        TreeNode* curr=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                }
                else{
                    root=root->right;
                }
            }
        }
        return curr;
    }
};
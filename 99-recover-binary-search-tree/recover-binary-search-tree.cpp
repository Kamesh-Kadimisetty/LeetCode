class Solution {
public:
    TreeNode* first,*last,*prev;
    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            if(prev!=NULL && root->val<prev->val){
                if(first==NULL){
                    first=prev;
                    last=root;
                }
                else{
                    last=root;
                }
            }
            prev=root;
            inorder(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        prev=first=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val,last->val);
    }
};
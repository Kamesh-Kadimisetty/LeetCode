class Solution {
public:
    void preorder(TreeNode* root,int &count){
        if(root!=NULL){
            count++;
            preorder(root->left,count);
            preorder(root->right,count);
        }
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int count=0;
        preorder(root,count);
        return count;
    }
};
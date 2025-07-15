class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode=new TreeNode(val);
        if(root==NULL) return newnode;
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->val>val){
                if(temp->left==NULL) break;
                temp=temp->left;
            }
            else{
                if(temp->right==NULL) break;
                temp=temp->right;
            }

        }
        if(temp->val>val) temp->left=newnode;
        else temp->right=newnode;
        return root;
    }
};
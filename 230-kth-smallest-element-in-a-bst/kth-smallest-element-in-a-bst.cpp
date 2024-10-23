class Solution {
public:
    void preorder(TreeNode* root,int &count,int &k,int& ksmallest){
        if(root!=NULL){
            preorder(root->left,count,k,ksmallest);
            count++;
            if(count==k){
                ksmallest=root->val;
            }
            preorder(root->right,count,k,ksmallest);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ksmallest=INT_MAX,count=0;
        preorder(root,count,k,ksmallest);
        return ksmallest;
    }
};
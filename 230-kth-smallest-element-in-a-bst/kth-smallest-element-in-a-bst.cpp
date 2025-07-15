class Solution {
public:
    int result;
    void inorder(TreeNode* root,int k,int& cnt){
        if(root!=NULL){
            inorder(root->left,k,cnt);
            cnt++;
            if(cnt==k){
                result=root->val;
                return;
            }
            inorder(root->right,k,cnt);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        inorder(root,k,cnt);
        return result;
    }
};
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder){
        int pre=0;
        int post=0;
        return func(pre,post,preorder,postorder);
    }
    TreeNode* func(int &pre,int &post,vector<int>&preorder,vector<int>&postorder){
        TreeNode* root=new TreeNode(preorder[pre]);
        pre++;
        if(root->val!=postorder[post]){
            root->left=func(pre,post,preorder,postorder);
        }
        if(root->val!=postorder[post]){
            root->right=func(pre,post,preorder,postorder);
        }
        post++;
        return root;
    }
};
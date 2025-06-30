class Solution {
public:
    int func(TreeNode* root,int &result){
        if(root==NULL) return 0;
        int l=func(root->left,result);
        int r=func(root->right,result);
        if(l<0) l=0;
        if(r<0) r=0;
        result=max(result,root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int result=INT_MIN;
        func(root,result);
        return result;
    }
};
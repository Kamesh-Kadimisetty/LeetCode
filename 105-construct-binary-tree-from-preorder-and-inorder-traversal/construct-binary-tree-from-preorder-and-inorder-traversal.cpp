class Solution {
public:
    TreeNode* func(vector<int>&preorder,int ps,int pe,
                    vector<int>&inorder,int is,int ie,unordered_map<int,int>&mpp){
        //BASE CASE
        if(ps>pe || is>ie){
            return NULL;
        }
        int index=mpp[preorder[ps]];
        int x=index-is;
        TreeNode* root=new TreeNode(preorder[ps]);
        root->left=func(preorder,ps+1,ps+x,inorder,is,index-1,mpp);
        root->right=func(preorder,ps+x+1,pe,inorder,index+1,ie,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++) mpp[inorder[i]]=i;
        return func(preorder,0,n-1,inorder,0,n-1,mpp);
    }
};
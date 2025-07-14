class Solution {
public:
    TreeNode* func(vector<int>& inorder,int is,int ie,
                vector<int>& postorder,int ps,int pe,unordered_map<int,int>&mpp){
        if(is>ie && ps>pe) return NULL;
        int index=mpp[postorder[pe]];
        int x=index-is;
        TreeNode* root=new TreeNode(postorder[pe]);
        root->left=func(inorder,is,index-1,postorder,ps,ps+x-1,mpp);
        root->right=func(inorder,index+1,ie,postorder,ps+x,pe-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++) mpp[inorder[i]]=i;
        return func(inorder,0,n-1,postorder,0,n-1,mpp);
    }
};
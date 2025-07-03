class Solution {
public:
    void func(TreeNode* root,int level,vector<int>& result){
        if(root==NULL) return;
        if(result.size()==level) result.push_back(root->val);
        func(root->right,level+1,result);
        func(root->left,level+1,result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        func(root,0,result);
        return result;
    }
};
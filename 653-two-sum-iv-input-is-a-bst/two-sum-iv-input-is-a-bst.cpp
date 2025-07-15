class Solution {
public:
    bool inorder(TreeNode* root,int k,unordered_map<int,int>& mpp){
        if(root!=NULL){
            if(inorder(root->left,k,mpp)==true) return true;
            int x=root->val;
            if(mpp.find(k-x)!=mpp.end()) return true;
            mpp[x]++;
            if(inorder(root->right,k,mpp)==true) return true;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mpp;
        return inorder(root,k,mpp);
    }
};
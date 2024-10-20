class Solution {
public:
    void preorder(TreeNode* root,vector<int>&arr){
        if(root!=NULL){
            arr.push_back(root->val);
            preorder(root->left,arr);
            preorder(root->right,arr);
        }
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        vector<int> arr;
        preorder(root,arr);
        return arr.size();
    }
};
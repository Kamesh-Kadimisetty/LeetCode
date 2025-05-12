/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool inorder(TreeNode* root,long long& prev){
        if(root!=NULL){
            if(inorder(root->left,prev)==false) return false;
            if(root->val<=prev){
                return false;
            }
            else{
                prev=root->val;
            }
            if(inorder(root->right,prev)==false) return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        long long prev=LLONG_MIN;
        return inorder(root,prev);
    }
};
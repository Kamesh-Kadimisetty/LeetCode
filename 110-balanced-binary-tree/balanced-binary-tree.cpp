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
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
    int check(TreeNode* root){
        if(root==NULL) return 0;
        int lf=check(root->left);
        if(lf==-1) return -1;
        int rt=check(root->right);
        if(rt==-1) return -1;
        if(abs(lf-rt)>1) return -1;
        
        return 1+max(lf,rt);
    }
};
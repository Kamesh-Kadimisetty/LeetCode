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
    void postorderhelper(TreeNode *currentNode,vector<int> &res){
        if(!currentNode){
            return;
        }
        postorderhelper(currentNode->left,res);
        postorderhelper(currentNode->right,res);
        res.push_back(currentNode->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderhelper(root,res);
        return res;
    }
};
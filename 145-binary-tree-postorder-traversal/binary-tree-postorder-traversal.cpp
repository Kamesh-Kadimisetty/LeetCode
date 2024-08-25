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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>transversalstack;
        TreeNode* currentnode=root;
        while(currentnode!=nullptr||!transversalstack.empty()){
            if(currentnode!=nullptr){
                result.push_back(currentnode->val);
                transversalstack.push(currentnode);
                currentnode=currentnode->right;
            }
            else{
                currentnode=transversalstack.top();
                transversalstack.pop();
                currentnode=currentnode->left;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
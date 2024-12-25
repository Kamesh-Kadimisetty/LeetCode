class Solution {
public:
    vector<int>result;
    vector<int> largestValues(TreeNode* root) {
        dfs(root,0);
        return result;
    }
    void dfs(TreeNode* root,int depth){
        if(root==NULL){
            return ;
        }
        if(depth==result.size()){
            result.push_back(root->val);
        }
        else{
            result[depth]=max(result[depth],root->val);
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
};
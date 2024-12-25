class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            int largest=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* node=qu.front();
                qu.pop();
                if(node->left)qu.push(node->left);
                if(node->right)qu.push(node->right);
                largest=max(largest,node->val);
            }
            result.push_back(largest);
        }
        return result;
    }
};
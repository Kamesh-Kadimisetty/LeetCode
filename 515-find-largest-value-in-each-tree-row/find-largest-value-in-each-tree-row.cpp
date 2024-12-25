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
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode* node=qu.front();
                qu.pop();
                if(node->left)qu.push(node->left);
                if(node->right)qu.push(node->right);
                level.push_back(node->val);
            }
            sort(level.begin(),level.end());
            int largest=*max_element(level.begin(),level.end());
            result.push_back(largest);
        }
        return result;
    }
};
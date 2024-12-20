class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>nd;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                nd.push_back(node);
            }
            if(level%2==1){
                int left=0,right=nd.size()-1;
                while(left<right){
                    swap(nd[left]->val,nd[right]->val);
                    left++;
                    right--;
                }
            }
            level++;
        }
        return root;
    }
};
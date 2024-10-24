class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr) return res;
        queue<TreeNode*>st;
        bool lefttoright=true;
        st.push(root);
        while(!st.empty()){
            long long sum=0;
            int n=st.size();
            vector<int>ans(n);
            for(int i=0;i<n;i++){
                TreeNode* it=st.front();
                st.pop();
                int index=lefttoright?i:n-i-1;
                ans[index]=it->val;
                if(it->left)  st.push(it->left);
                if(it->right) st.push(it->right);
            }
            lefttoright=!lefttoright;
            res.push_back(ans);
        }
        return res;
    }
};
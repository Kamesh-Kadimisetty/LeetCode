class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr) return res;
        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            long long sum=0;
            int n=st.size();
            vector<int>ans;
            for(int i=0;i<n;i++){
                TreeNode* it=st.front();
                st.pop();
                if(it->right) st.push(it->right);
                if(it->left)  st.push(it->left);
                ans.push_back(it->val);
            }
            res.push_back(ans);
        }
        for(int i=2;i<res.size();i+=2){
            reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};
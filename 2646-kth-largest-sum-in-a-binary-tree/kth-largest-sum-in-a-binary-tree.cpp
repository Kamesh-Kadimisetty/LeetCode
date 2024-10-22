class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==nullptr) return -1;
        vector<long long >res;
        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            long long sum=0;
            int n=st.size();
            for(int i=0;i<n;i++){
                TreeNode* it=st.front();
                st.pop();
                if(it->right) st.push(it->right);
                if(it->left)  st.push(it->left);
                sum+=it->val;
            }
            res.push_back(sum);
        }
        sort(res.rbegin(),res.rend());
        return k<=res.size()?res[k-1]:-1;
    }
};
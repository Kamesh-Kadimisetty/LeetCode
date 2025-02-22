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
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.size();
        TreeNode* dummy=new TreeNode(-1);
        int i=0;
        stack<TreeNode* >st;
        while(i<n){
            int depth=0;
            while(i<n && traversal[i]=='-'){
                depth++;
                i++;
            }
            string num="";
            while(i<n && traversal[i]!='-'){
                num=traversal[i]+num;
                i++;
            }
            reverse(num.begin(),num.end());
            int value=stoi(num);
            cout<<depth<<" ";
            TreeNode* root=new TreeNode(value);
            while(st.size()>depth){
                st.pop();
            }
            if(st.empty()){
                dummy->left=root;
            }
            else{
                if(st.top()->left==NULL){
                    st.top()->left=root;
                }
                else{
                    st.top()->right=root;
                }
            }
            st.push(root);
            // cout<<st.size()<<" ";
            // i++;
        }
        return dummy->left;
    }
};
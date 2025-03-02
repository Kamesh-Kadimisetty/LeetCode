class Solution {
public:
    int i=0;
    void inorder(TreeNode* root,vector<int>&values){
        if(root!=NULL){
            inorder(root->left,values);
            values.push_back(root->val);
            inorder(root->right,values);
        }
    }
    void changevalues(TreeNode* &root,vector<int>&values,int &totalsum){
        if(root!=NULL){
            changevalues(root->left,values,totalsum);
            root->val=totalsum;
            totalsum-=values[i];
            i++;
            changevalues(root->right,values,totalsum);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>values;
        inorder(root,values);
        int totalsum=accumulate(values.begin(),values.end(),0);
        changevalues(root,values,totalsum);
        return root;
    }
};
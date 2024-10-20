class Solution {
public:
    int height(TreeNode* root,int &diameter){
        if(root==nullptr){
            return 0;
        }
        int lf=height(root->left,diameter);
        int rt=height(root->right,diameter);
        diameter=max(diameter,lf+rt);
        return 1+max(lf,rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};
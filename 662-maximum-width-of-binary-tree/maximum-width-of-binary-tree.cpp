class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>qu;
        qu.push({root,0});
        int maxlen=1;
        while(!qu.empty()){
            long long n=qu.size(),left,right,minindex=qu.front().second;
            for(int i=0;i<n;i++){
                TreeNode* curr=qu.front().first;
                long long col=qu.front().second-minindex;
                qu.pop();
                if(i==0) left=col;
                if(i==n-1) right=col;
                if(curr->left){
                    qu.push({curr->left,2*col});
                }
                if(curr->right){
                    qu.push({curr->right,2*col+1});
                }
            }
            int ans=right-left+1;
            maxlen=max(maxlen,ans);
        }
        return maxlen;
    }
};
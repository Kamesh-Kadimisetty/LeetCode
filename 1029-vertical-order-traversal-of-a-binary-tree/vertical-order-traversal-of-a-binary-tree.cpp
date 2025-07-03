class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mpp; //{col,level,val} 
        queue<pair<TreeNode*,pair<int,int>>>qu;  //{node,{level,column}}
        qu.push({root,{0,0}});
        while(!qu.empty()){
            TreeNode* curr=qu.front().first;
            int level=qu.front().second.first;
            int col=qu.front().second.second;
            qu.pop();
            mpp[col][level].insert(curr->val);
            if(curr->left){
                qu.push({curr->left,{level+1,col-1}});
            }
            if(curr->right){
                qu.push({curr->right,{level+1,col+1}});       
            }
        }
        vector<vector<int>>result;
        for(auto it:mpp){
            vector<int>colm;
            for(auto p:it.second){
                colm.insert(colm.end(),p.second.begin(),p.second.end());
            }
            result.push_back(colm);
        }
        return result;
    }
};
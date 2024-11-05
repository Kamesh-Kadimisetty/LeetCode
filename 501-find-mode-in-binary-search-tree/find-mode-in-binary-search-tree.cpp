class Solution {
public:
    void traversal(TreeNode* root,unordered_map<int,int>&freq){
        if(root!=NULL){
            freq[root->val]++;
            traversal(root->left,freq);
            traversal(root->right,freq);
        }
    }
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        unordered_map<int,int>freq;
        traversal(root,freq);
        int maxfreq=0;
        for (auto i: freq) {
            maxfreq = max(maxfreq,i.second);
        }
        vector<int>result;
        for (auto i: freq) {
            if(i.second==maxfreq){
                result.push_back(i.first);
            }
        }
        return result;
    }
};
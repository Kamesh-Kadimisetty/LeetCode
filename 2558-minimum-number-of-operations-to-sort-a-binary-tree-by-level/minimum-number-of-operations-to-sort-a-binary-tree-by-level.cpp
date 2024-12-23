class Solution {
public:
    int getswaps(vector<int>&nums){
        int swaps=0;
        vector<int>target(nums);
        sort(target.begin(),target.end());
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=target[i]){
                swaps++;
                int curr=mpp[target[i]];
                mpp[nums[i]]=curr;
                swap(nums[i],nums[curr]);
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        int totalswaps=0;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            vector<int>nums;
            int n=qu.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=qu.front();
                qu.pop();
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
                nums.push_back(curr->val);
            }
            totalswaps+=getswaps(nums);
        }
        return totalswaps;
    }
};
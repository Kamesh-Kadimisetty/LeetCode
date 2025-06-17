class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size(),m=operations.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        for(auto it:operations){
            int ind=mpp[it[0]];
            mpp.erase(it[0]);
            mpp[it[1]]=ind;
        }
        for(auto it:mpp){
            nums[it.second]=it.first;
        }
        return nums;
    }
};
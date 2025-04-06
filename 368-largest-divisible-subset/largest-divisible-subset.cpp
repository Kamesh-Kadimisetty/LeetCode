class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res(n);
        for(int i=0;i<n;i++){
            res[i]={nums[i]};
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && res[i].size()<res[j].size()+1){
                    res[i]=res[j];
                    res[i].push_back(nums[i]);
                }
            }
        }
        vector<int>ans;
        for(auto it:res){
            if(it.size()>ans.size()){
                ans=it;
            }
        }
        return ans;
    }
};
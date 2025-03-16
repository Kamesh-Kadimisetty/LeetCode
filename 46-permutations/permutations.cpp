class Solution {
public:
    void func(vector<int>&arr,vector<int>&hash,vector<vector<int>>&result,vector<int>& nums){
        if(arr.size()==nums.size()){
            result.push_back(arr);
            return;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]==0){
                arr.push_back(nums[i]);
                hash[i]=1;
                func(arr,hash,result,nums);
                arr.pop_back();
                hash[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();
        vector<int>arr;
        vector<int>hash(n,0);
        func(arr,hash,result,nums);
        return result;
    }
};
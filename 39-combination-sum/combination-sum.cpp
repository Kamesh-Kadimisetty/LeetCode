class Solution {
public:
    void func(int ind,vector<int>&arr,set<vector<int>>&result,vector<int>& candidates, int target){
        if(target==0){
            result.insert(arr);
        }
        if(ind==candidates.size() || target<0) return;
        arr.push_back(candidates[ind]);
        func(ind,arr,result,candidates,target-candidates[ind]);
        arr.pop_back();
        func(ind+1,arr,result,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>result;
        vector<int>arr;
        func(0,arr,result,candidates,target);
        vector<vector<int>>ans(result.begin(),result.end());
        return ans;
    }
};
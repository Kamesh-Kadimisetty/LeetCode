class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(candidates.begin(),candidates.end());
        combination(0,target,candidates,res,ans);
        return ans;
    }
    void combination(int ind,int target,vector < int > & arr,vector<int> &res,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            res.push_back(arr[i]);
            combination(i+1,target-arr[i],arr,res,ans);
            res.pop_back();
        }
    }
};
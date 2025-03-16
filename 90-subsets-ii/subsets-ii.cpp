class Solution {
public:
    void func(int ind,vector<int>&arr,set<vector<int>>&st,vector<int>&nums){
        if(ind>=nums.size()){
            st.insert(arr);
            return;
        }
        arr.push_back(nums[ind]);
        func(ind+1,arr,st,nums);
        arr.pop_back();
        func(ind+1,arr,st,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>arr;
        func(0,arr,st,nums);
        vector<vector<int>>result(st.begin(),st.end());
        return result;
    }
};
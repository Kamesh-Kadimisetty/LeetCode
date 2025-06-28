class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result;
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++) arr.push_back({nums[i],i});
        sort(arr.rbegin(),arr.rend());
        vector<pair<int,int>>pq;
        for(int i=0;i<k;i++) pq.push_back({arr[i].second,arr[i].first});
        sort(pq.begin(),pq.end());
        for(auto it:pq) result.push_back(it.second);
        return result;
    }
};
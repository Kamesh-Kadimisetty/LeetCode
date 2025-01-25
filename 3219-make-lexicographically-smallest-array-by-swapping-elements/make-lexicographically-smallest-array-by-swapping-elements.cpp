class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>result(n);
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>>indexes;
        for(int i=0;i<n;i++){
            if(i==0 || arr[i].first-arr[i-1].first>limit){
                indexes.push_back({});
            }
            indexes.back().push_back(arr[i].second);
        }
        for(auto it:indexes){
            vector<int>index(it);
            sort(index.begin(),index.end());
            for(int i=0;i<it.size();i++){
                result[index[i]]=nums[it[i]];
            }
        }
        return result;
    }
};
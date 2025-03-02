class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int>mpp;
        int n=nums1.size(),m=nums2.size();
        for(auto it:nums1){
            if(mpp.find(it[0])!=mpp.end()){
                mpp[it[0]]=mpp[it[0]]+it[1];
            }
            else{
                mpp[it[0]]=it[1];
            }
        }
        for(auto it:nums2){
            if(mpp.find(it[0])!=mpp.end()){
                mpp[it[0]]=mpp[it[0]]+it[1];
            }
            else{
                mpp[it[0]]=it[1];
            }
        }
        vector<vector<int>>result;
        for(auto it:mpp){
            result.push_back({it.first,it.second});
        }
        sort(result.begin(),result.end());
        return result;
    }
};
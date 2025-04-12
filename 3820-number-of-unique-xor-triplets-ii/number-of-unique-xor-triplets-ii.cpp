class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st,st1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        for(auto it:st){
            for(auto k:nums){
                st1.insert(it^k);
            }
        }
        return st1.size();
    }
};
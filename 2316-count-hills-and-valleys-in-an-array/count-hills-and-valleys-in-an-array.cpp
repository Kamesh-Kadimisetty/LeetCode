struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        unordered_set<pair<int,int>,pair_hash>st;
        for(int i=1;i<n-1;i++){
            int j=i,k=i;
            while(j>0 && nums[j]==nums[i]){
                j--;
            }
            while(k<n-1 && nums[k]==nums[i]){
                k++;
            }
            if(nums[i]>nums[j] && nums[i]>nums[k]){
                st.insert({j,k});
            } 
            if(nums[i]<nums[j] && nums[i]<nums[k]){
                st.insert({j,k});
            } 
        }
        return st.size();
    }
};
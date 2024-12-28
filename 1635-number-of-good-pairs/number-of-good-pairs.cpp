class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>hash(101,0);
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]>0){
                ans+=floor(hash[i]*(hash[i]-1))/2;
            }
        }
        return ans;
    }
};
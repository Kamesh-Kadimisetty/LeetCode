class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mpp1,mpp2;
        int cnt=0,MOD=1e9+7;
        for(auto it:nums) mpp1[it]++;
        for(auto it:nums){
            mpp1[it]--;
            cnt=(cnt+1LL*mpp1[2*it]*mpp2[2*it])%MOD;
            mpp2[it]++;
        }
        return cnt;
    }
};
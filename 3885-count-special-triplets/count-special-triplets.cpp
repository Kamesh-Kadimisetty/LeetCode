class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mpp1,mpp2;
        int n=nums.size(),zeros=0,cnt=0,MOD=1e9+7;
        for(auto it:nums) mpp1[it]++;
        for(auto it:nums){
            if(it==0){
                zeros++;
                continue;
            }
            int x=2*it;
            if(mpp1.find(x)!=mpp1.end() && mpp2.find(x)!=mpp2.end()){
                cnt=(cnt+(mpp1[x]*mpp2[x])%MOD)%MOD;
            }
            mpp1[it]--;
            if(mpp1[it]==0) mpp1.erase(it);
            mpp2[it]++;
        }
        cnt=cnt+(((1LL*zeros*(zeros-1))*(zeros-2))/6)%MOD;
        return cnt;
    }
};
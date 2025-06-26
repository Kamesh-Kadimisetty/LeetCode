class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size(),MOD=1e9+7;
        vector<int>diffarr(n+1,0);
        for(auto it:requests){
            diffarr[it[0]]++;
            diffarr[it[1]+1]--;
        }
        for(int i=1;i<n;i++){
            diffarr[i]+=diffarr[i-1];
        }
        diffarr.erase(diffarr.begin()+n);
        sort(nums.rbegin(),nums.rend());
        sort(diffarr.rbegin(),diffarr.rend());
        int sum=0;
        for(int i=0;i<n;i++){
            if(diffarr[i]==0) break;
                sum=(sum+(1LL*diffarr[i]*nums[i])%MOD)%MOD;
        }   
        return sum;
    }
};
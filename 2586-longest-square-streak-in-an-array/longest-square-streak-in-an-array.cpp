class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int maxstreak=-1;
        for(auto num:nums){
            int count=0;
            long long i=num;
            while(st.find(int(i))!=st.end()){
                count++;
                if (i*i >1e5) break;
                i=i*i;
            }
            maxstreak=max(maxstreak,count);
        }
        return maxstreak > 1 ? maxstreak : -1;
    }
};
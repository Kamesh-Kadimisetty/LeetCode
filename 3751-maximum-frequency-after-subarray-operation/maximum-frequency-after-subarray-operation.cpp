class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size(),kfreq=0,maxkcnt=0;
        for(auto it:nums){
            if(it==k) {
                kfreq++;
            }
        }
        for(int i=1;i<=50;i++){
            if(i==k)continue;
            int cnt=0,maxcnt=0;
            for(auto it:nums){
                if(it==i){
                    cnt++;
                }
                else if(it==k){
                    cnt--;
                }
                if(cnt<0){
                    cnt=0;
                }
                maxcnt=max(maxcnt,cnt);
            }
            maxkcnt=max(maxkcnt,maxcnt);
        }
        return maxkcnt+kfreq;
    }
};
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=n-2;
        nums[n-1]+=k;
        int maxi=nums[n-1];
        while(i>=0){
            int x=maxi-nums[i]-1;
            while(x>k){
                x--;
            }
            if(x<-k){
                i--;
                continue;
            }
            nums[i]+=x;
            maxi=nums[i];
            i--;
        }
        set<int>stt(nums.begin(),nums.end());
        return stt.size();
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int smaller=INT_MIN,count=0,longest=1; 
        for(int i=0;i<n;i++){
            if(nums[i]-1==smaller){
                count++;
                smaller=nums[i];
            }
            else if(nums[i]!=smaller){
                count=1;
                smaller=nums[i];
            }
            longest=max(count,longest);
        }
        return longest;
    }
};
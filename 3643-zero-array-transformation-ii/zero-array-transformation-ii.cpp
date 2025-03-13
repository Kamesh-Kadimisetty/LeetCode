class Solution {
public:
    bool ispossible(vector<int>& nums, vector<vector<int>>& queries,int mid){
        int n=nums.size();
        vector<int>diff(n+1,0);
        for(int i=0;i<mid;i++){
            int l=queries[i][0],r=queries[i][1],k=queries[i][2];
            diff[l]+=k;
            diff[r+1]-=k;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum<nums[i])return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries){
        int n=nums.size();
        int low=0,high=queries.size();
        if(!ispossible(nums,queries,high)) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(nums,queries,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
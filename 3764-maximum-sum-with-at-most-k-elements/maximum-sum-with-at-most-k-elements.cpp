class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long maxsum=0;
        if(k==0)return 0;
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[i].push_back(grid[i][j]);
            }
        }
        vector<int>all;
        for(int i=0;i<n;i++){
            int cnt=limits[i];
            vector<int>nums=mpp[i];
            sort(nums.begin(),nums.end());
            for(int i=m-1;i>=0;i--){
                if(cnt==0){
                    break;
                }
                cnt--;
                all.push_back(nums[i]);
            }
        }
        sort(all.begin(),all.end());
        cout<<all.size();
        for(int i=all.size()-1;i>=0;i--){
            k--;
            maxsum+=all[i];
            
            if(k==0){
                break;
            }
        }
        return maxsum;
    }
};
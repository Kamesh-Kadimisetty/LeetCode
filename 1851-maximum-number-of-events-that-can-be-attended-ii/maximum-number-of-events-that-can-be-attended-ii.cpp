class Solution {
public:
    int bs(int target,vector<vector<int>>& events){
        int low=0,high=events.size();
        while(low<high){
            int mid=(low+high)/2;
            if(events[mid][0]<=target){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
    int func(int curr,vector<vector<int>>& events,int k,vector<vector<int>>& dp){
        int n=events.size();
        if(k==0 || curr==n) return 0;
        if(dp[curr][k]!=-1) return dp[curr][k];
        int next=bs(events[curr][1],events);
        int take=events[curr][2]+func(next,events,k-1,dp);
        int notake=func(curr+1,events,k,dp);
        return dp[curr][k]=max(take,notake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
       int n=events.size();
       sort(events.begin(),events.end());
       vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
       return func(0,events,k,dp);
    }
};
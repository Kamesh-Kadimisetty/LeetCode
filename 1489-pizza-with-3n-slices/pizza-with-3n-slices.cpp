class Solution {
public:
    int func(int x,vector<int>slices){
        int n=slices.size();
        vector<vector<int>>dp(n+2,vector<int>(x+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int j=1;j<=x;j++){
                dp[ind][j]=max(slices[ind]+dp[ind+2][j-1],dp[ind+1][j]);
            }   
        }
        return dp[0][x];
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size(),x=n/3;
        return max(func(x,vector<int>(slices.begin(),slices.end()-1)),
                    func(x,vector<int>(slices.begin()+1,slices.end())));
    }
};
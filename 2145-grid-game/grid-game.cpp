class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long result=LLONG_MAX;
        long long row1=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long row2=0;
        for(int i=0;i<grid[0].size();i++){
            row1-=grid[0][i];
            result=min(result,max(row1,row2));
            row2+=grid[1][i];
        }
        return result;
    }
};
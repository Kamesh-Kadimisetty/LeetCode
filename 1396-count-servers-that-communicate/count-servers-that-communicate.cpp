class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>rows(n,0);
        vector<int>cols(m,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && rows[i]==1 && cols[j]==1){
                    cnt--;
                }
            }
        }
        return cnt;
    }
};
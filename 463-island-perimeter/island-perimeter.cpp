class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0,repeat=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    islands++;
                    if(i!=0 && grid[i-1][j]==1) repeat++;
                    if(j!=0 && grid[i][j-1]==1) repeat++;
                }
            }
        }
        return 4*islands-repeat*2;
    }
};
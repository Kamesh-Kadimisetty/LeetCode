class Solution {
    int magic(int r,int c,vector<vector<int>>& grid){
            vector<int> count(10,0);
            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    int num=grid[r+x][c+y];
                    if(num<1 || num>9 ||count[num]>0)
                    return 0;
                    count[num]++;
                }
            }
            for(int i=r;i<r+3;i++){
                if((grid[i][c]+grid[i][c+1]+grid[i][c+2])!=15)
                return 0;
            }
            for(int i=c;i<c+3;i++){
                if((grid[r][i]+grid[r+1][i]+grid[r+2][i])!=15)
                return 0;
            }
            if(
                grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=15 ||
                grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=15){
            return 0;
            }
            return 1;
        }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int res=0;
        for(int i=0;i<rows-2;i++){
            for(int j=0;j<cols-2;j++){
                res+=magic(i,j,grid);
            }
        }
        return res;
    }
};
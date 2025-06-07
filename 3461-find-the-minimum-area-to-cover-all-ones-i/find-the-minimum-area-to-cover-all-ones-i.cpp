class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int minx=INT_MAX,maxx=INT_MIN;
        int miny=INT_MAX,maxy=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    minx=min(minx,i);
                    maxx=max(maxx,i);
                    miny=min(miny,j);
                    maxy=max(maxy,j);
                }
            }
        }
        cout<<minx<<" "<<maxx<<endl;
        cout<<miny<<" "<<maxy<<endl;
        return (maxx-minx+1)*(maxy-miny+1);
    }
};
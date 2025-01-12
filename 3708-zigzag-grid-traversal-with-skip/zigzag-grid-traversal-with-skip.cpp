class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>result;
        int n=grid.size();
        int m=grid[0].size();
        int i=0,j=0,flag=0;
        while(i<n){
            for(int j=0;j<m;j++){
                if(flag==0){
                    result.push_back(grid[i][j]);
                    flag=1;
                }
                else{
                    flag=0;
                }
            }
            if(i<n)i++;
            if(i==n)break;
            for(int j=m-1;j>=0;j--){
                 if(flag==0){
                    result.push_back(grid[i][j]);
                    flag=1;
                }
                else{
                    flag=0;
                }
            }
            if(i<n)i++;
            if(i==n)break;
        }
        return result;
    }
};
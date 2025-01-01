class Solution {
public:
    vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& image,vector<vector<int>>& result,int sr,int sc,int col,int initcol){
        result[sr][sc]=col;
        int n=image.size();
        int m=image[0].size();
        for(auto [dr,dc]:directions){
            int r=sr+dr;
            int c=sc+dc;
            if(r>=0 && r<n && c>=0 && c<m && image[r][c]==initcol && result[r][c]!=col){
            dfs(image,result,r,c,col,initcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>result=image;
        int initcol=image[sr][sc];
        dfs(image,result,sr,sc,color,initcol);
        return result;
    }
};
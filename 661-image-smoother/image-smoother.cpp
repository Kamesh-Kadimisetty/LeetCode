class Solution {
public:
    int func(int r,int c,vector<vector<int>>& img){
        int n=img.size(),m=img[0].size();
        int sum=0,cnt=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nr=r+i,nc=c+j;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    cnt++;
                    sum+=img[nr][nc];
                }
            }
        }
        return sum/cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>result(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j]=func(i,j,img);
            }
        }
        return result;
    }
};
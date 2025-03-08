class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][via]==INT_MAX || mat[via][j]==INT_MAX){
                        continue;
                    }
                    mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
        int city=-1,maxcites=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
                for(int j=0;j<n;j++){
                    if(mat[i][j]<=distanceThreshold && mat[i][j]!=0){
                        cnt++;
                    }
                }
                if(maxcites>=cnt){
                    maxcites=cnt;
                    city=i;
                }
            }
        return city;
    }
};
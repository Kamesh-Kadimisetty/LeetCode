class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>>rotated(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rotated[i][j]=box[m-1-j][i];
            }
        }
        for(int j=0;j<m;j++){
            int empty=n-1;
            for(int i=n-1;i>=0;i--){
                if(rotated[i][j]=='#'){
                    rotated[i][j]='.';
                    rotated[empty][j]='#';
                    empty--;
                }
                if(rotated[i][j]=='*'){
                    empty=i-1;
                }
            }
        }
        return rotated;
    }
};
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=k;
                k++;
            }
        }
        int a=0,b=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]=="DOWN"){
                a++;
            }
            else if(commands[i]=="UP"){
                a--;
            }
            else if(commands[i]=="RIGHT"){
                b++;
            }
            else{
                b--;
            }
        }
        return ans[a][b];
    }
};
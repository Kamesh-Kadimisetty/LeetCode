class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>board1;
        board1.push_back(-1);
        for(int i=n-1;i>=0;i--){
            if((n%2==1 && i%2==0) || (n%2==0 && i%2==1)){
                for(int j=0;j<n;j++){
                    board1.push_back(board[i][j]);
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    board1.push_back(board[i][j]);
                }
            }
        }
        vector<int>visited(n*n+1,0);
        queue<pair<int,int>>qu;
        qu.push({1,0});
        visited[1]=1;
        while(!qu.empty()){
            int curr=qu.front().first;
            int moves=qu.front().second;
            qu.pop();
            if(curr==n*n) return moves;
            for(int i=1;i<=6;i++){
                int x=curr+i;
                if(x<=n*n){
                    int next=board1[x]==-1?x:board1[x];
                    if(!visited[next]){
                        qu.push({next,moves+1});
                        visited[next]=1;
                    }
                }
            }
        }
        return -1;
    }
};
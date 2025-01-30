class Solution {
public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&left,vector<int>&upperdiagonal,vector<int>&lowerdiagonal,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && upperdiagonal[row+col]==0 && lowerdiagonal[n-1+row-col]==0){
                board[row][col]='Q';
                left[row]=1;
                upperdiagonal[row+col]=1;
                lowerdiagonal[n-1+row-col]=1;
                solve(col+1,board,ans,left,upperdiagonal,lowerdiagonal,n);
                board[row][col]='.';
                left[row]=0;
                upperdiagonal[row+col]=0;
                lowerdiagonal[n-1+row-col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>left(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        solve(0,board,ans,left,upperdiagonal,lowerdiagonal,n);
        return ans;
    }
};
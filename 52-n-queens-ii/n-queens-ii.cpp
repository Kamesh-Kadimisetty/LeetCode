class Solution {
public:
    void solve(int col,vector<string>&board,vector<int>&left,vector<int>&upperdiag,vector<int>&lowerdiag,int n,int &cnt){
        if(col==n){
            cnt++;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && upperdiag[row+col]==0 && lowerdiag[n-1+row-col]==0){
                board[row][col]='Q';
                left[row]=1;
                upperdiag[row+col]=1;
                lowerdiag[n-1+row-col]=1;
                solve(col+1,board,left,upperdiag,lowerdiag,n,cnt);
                board[row][col]='.';
                left[row]=0;
                upperdiag[row+col]=0;
                lowerdiag[n-1+row-col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        int cnt=0;
        vector<int>left(n,0);
        vector<int>upperdiag(2*n-1,0);
        vector<int>lowerdiag(2*n-1,0);
        solve(0,board,left,upperdiag,lowerdiag,n,cnt);
        return cnt;
    }
};
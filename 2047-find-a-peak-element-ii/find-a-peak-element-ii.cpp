class Solution {
public:
    int max_ele(vector<vector<int>>& mat,int n,int m,int col){
        int ind=-1,maxele=INT_MIN;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxele){
                maxele=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=max_ele(mat,n,m,mid);
            int left=mid-1>=0 ? mat[row][mid-1]:INT_MIN;
            int right=mid+1<m ? mat[row][mid+1]:INT_MIN;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};
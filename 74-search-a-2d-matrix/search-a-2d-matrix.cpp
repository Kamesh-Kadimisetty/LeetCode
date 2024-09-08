class Solution {
public:
    int binary_search(vector<int>& matrix,int target){
        int low=0,high=matrix.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid]==target) return mid;
            else if(matrix[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int ind=binary_search(matrix[i],target);
            if(ind!=-1) return true;
        }
        return false;
    }
};
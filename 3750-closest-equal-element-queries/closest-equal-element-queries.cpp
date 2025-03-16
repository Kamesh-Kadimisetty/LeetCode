class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int>result;
        for(auto &it:queries){
            int num=nums[it];
            vector<int>&arr=mpp[num];
            int m=arr.size();
            if(m<2){
                result.push_back(-1);
                continue;
            }
            int low=0,high=m-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]==it){
                    int left=arr[(mid-1+m)%m];
                    int right=arr[(mid+1)%m];
                    int leftdist=abs(it-left);
                    int rightdist=abs(it-right);
                    leftdist=min(leftdist,n-leftdist);
                    rightdist=min(rightdist,n-rightdist);
                    result.push_back(min(leftdist,rightdist));
                    break;
                }
                else if(arr[mid]<it){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return result;
    }
};
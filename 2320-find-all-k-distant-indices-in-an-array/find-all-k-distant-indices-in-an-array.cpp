class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>result;
        int n=nums.size(),j=0;
        while(j<n && nums[j]!=key){
            j++;
            if(j==n) return result;
        }
        cout<<j;
        for(int i=0;i<n;i++){
            if(abs(i-j)<=k) result.push_back(i);
            if(abs(i+1-j)>k && j<i){
                j++;
                while(j<n && nums[j]!=key){
                    j++;
                    if(j==n) return result;
                }
            }
        }
        return result;
    }
};
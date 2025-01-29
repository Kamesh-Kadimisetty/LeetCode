class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        vector<vector<int>>result;
        int count=n;
        while(count!=0){
            vector<int>temp;
            for(int i=1;i<n+1;i++){
                if(hash[i]>0){
                    temp.push_back(i);
                    hash[i]--;
                    count--;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
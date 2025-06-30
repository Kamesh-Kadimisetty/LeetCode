class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int maxlen=0;
        for(auto it:mpp){
            if(mpp.find(it.first+1)!=mpp.end()){
                maxlen=max(maxlen,it.second+mpp[it.first+1]);
            }
        }
        return maxlen;
    }
};
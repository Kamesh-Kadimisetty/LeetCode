class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        for(auto it:arr){
            if(mpp[it]>0 && mpp[2*it]>0){
                mpp[it]--;
                mpp[2*it]--;
            }
        }
        for(auto it:mpp){
            if(it.second>0)return false;
        }
        return true;    
    }
};
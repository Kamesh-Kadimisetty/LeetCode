class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mpp;
        for(auto it:arr) mpp[it]++;
        auto it=mpp.rbegin();
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            if(it->first==it->second) return it->first;
        }
        return -1;
    }
};
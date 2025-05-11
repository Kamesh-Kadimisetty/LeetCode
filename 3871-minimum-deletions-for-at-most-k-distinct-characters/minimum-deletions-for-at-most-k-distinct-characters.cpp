class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        if(mpp.size()<=k) return 0;
        vector<int>arr;
        for(auto it:mpp){
            arr.push_back(it.second);
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<arr.size()-k;i++){
            ans+=arr[i];
        }
        return ans;
    }
};
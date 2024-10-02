class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<int>sortarr=arr;
        sort(sortarr.begin(),sortarr.end());
        unordered_map<int,int> rankmap;
        int j=1;
        for(int i=0;i<arr.size();i++){
            if(rankmap.find(sortarr[i])==rankmap.end()){
                rankmap[sortarr[i]]=j++;
            }
        }
        vector<int> result;
        for(int i=0;i<arr.size();i++){
            result.push_back(rankmap[arr[i]]);
        }
        return result;
    }
};
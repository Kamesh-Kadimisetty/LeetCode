class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mpp,map1,map2;
        int n=basket1.size(),minele=INT_MAX;
        for(auto it:basket1){
            mpp[it]++;
            map1[it]++;
            minele=min(minele,it);
        }
        for(auto it:basket2){
            mpp[it]++;
            map2[it]++;
            minele=min(minele,it);
        }
        vector<int>arr1,arr2;
        for(auto it:mpp){
            if(it.second%2!=0) return -1;
            int num=it.first,cnt=it.second/2;
            int req=cnt;
            if(map1.find(num)!=map1.end()){
                req=cnt-map1[num];
            }
            for(int i=0;i<req;i++){
                arr1.push_back(num);
            }
            req=cnt;
            if(map2.find(num)!=map2.end()){
                req=cnt-map2[num];
            }
            for(int i=0;i<req;i++){
                arr2.push_back(num);
            }
        }
        if(arr1.size()!=arr2.size()) return -1;
        sort(arr1.begin(),arr1.end());
        sort(arr2.rbegin(),arr2.rend());
        long long result=0;
        for(int i=0;i<arr1.size();i++){
            result+=min(2*minele,min(arr1[i],arr2[i]));
        }
        return result;
    }
};
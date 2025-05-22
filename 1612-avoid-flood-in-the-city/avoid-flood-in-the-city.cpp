class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>result(n,1);
        vector<int>arr;
        unordered_map<int,int>visited;
        for(int i=0;i<n;i++){
            if(rains[i]>0){
                if(visited.find(rains[i])!=visited.end()){
                    auto x=upper_bound(arr.begin(),arr.end(),visited[rains[i]]);
                    if(x==arr.end()) return {};
                    result[*x]=rains[i];
                    arr.erase(x);
                }
                result[i]=-1;
                visited[rains[i]]=i;
            }
            else{
                arr.push_back(i);
            }
        }
        return result;
    }
};
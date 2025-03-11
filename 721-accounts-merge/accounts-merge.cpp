class Solution {
public:
    //USING DISJOINT SETS
    vector<int> parent,size;
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)!=mpp.end()){
                    unionBySize(i,mpp[mail]);
                }
                else{
                    mpp[mail]=i;
                }
            }
        }
        
        vector<vector<string>>mergedmail(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=it.second;
            mergedmail[findUPar(node)].push_back(mail);
        }

        vector<vector<string>>result;
        
        for(int i=0;i<n;i++){
            if(mergedmail[i].size()==0)continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedmail[i]){
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }
};
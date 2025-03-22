class Disjointset{
public:
    vector<int>parent,size;
    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulpu=findparent(u);
        int ulpv=findparent(v);
        if(ulpv==ulpu){
            return;
        }
        if(size[ulpu]>size[ulpv]){
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
        else{
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Disjointset ds(n+1);
        vector<int>indegree(n,0);
        for(auto it:edges){
            ds.unionbysize(it[0],it[1]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int parent=ds.findparent(i);
            mpp[parent]++;
        }
        for(int i=0;i<n;i++){
            int parent=ds.findparent(i);
            if(mpp.find(parent)!=mpp.end() && indegree[i]!=mpp[parent]-1){
                mpp.erase(parent);
            }
        }
        return mpp.size();
    }
};
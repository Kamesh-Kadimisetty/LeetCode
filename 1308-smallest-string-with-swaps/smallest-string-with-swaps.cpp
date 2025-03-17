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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        Disjointset ds(n);
        for(auto it:pairs){
            ds.unionbysize(it[0],it[1]);
        }
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[ds.findparent(i)].push_back(i);
        }
        string ans=s;
        for(auto it:mpp){
            string compo;
            for(auto ch:it.second){
                compo+=s[ch];
            }
            sort(compo.begin(),compo.end());
            for(int i=0;i<it.second.size();i++){
                ans[it.second[i]]=compo[i];
            }
        }
        return ans;
    }
};
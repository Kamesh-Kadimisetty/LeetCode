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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        Disjointset ds(maxrow+maxcol+1);
        set<int>st;
        for(auto it:stones){
            int row=it[0];
            int col=maxrow+1+it[1];
            ds.unionbysize(row,col);
            st.insert(row);
            st.insert(col);
        }
        int cnt=0;
        for(auto it:st){
            if(ds.findparent(it)==it)cnt++;
        }
        return n-cnt;
    }
};
class Disjointset{
public:
    vector<int>parent,size;
    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) parent[i]=i;
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Disjointset ds(26);
        int n=s1.size();
        for(int i=0;i<n;i++){
            ds.unionbysize(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++){
            for(int j=0;j<26;j++){
                if(ds.findparent(baseStr[i]-'a')==ds.findparent(j)){
                    baseStr[i]=j+'a';
                    break;
                }
            }
        }
        return baseStr;
    }
};
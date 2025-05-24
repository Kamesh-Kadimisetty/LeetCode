class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        vector<int>nodes;
        for(int i=1;i<=n;i++){
            if(adj[i].size()%2==1){
                nodes.push_back(i);
            } 
        }
        cout<<nodes.size();
        if(nodes.size()==2){
            for(int i=1;i<=n;i++){
                if(adj[nodes[0]].count(i)==0 && adj[nodes[1]].count(i)==0) return true;
            }
        }
        if(nodes.size()==4){
            return  (adj[nodes[0]].count(nodes[1])==0 && adj[nodes[2]].count(nodes[3])==0) 
                ||  (adj[nodes[0]].count(nodes[2])==0 && adj[nodes[1]].count(nodes[3])==0)  
                ||  (adj[nodes[0]].count(nodes[3])==0 && adj[nodes[1]].count(nodes[2])==0);
        }
        return nodes.size()==0;
    }
};
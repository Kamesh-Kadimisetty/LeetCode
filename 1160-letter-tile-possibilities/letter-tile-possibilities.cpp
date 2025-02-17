class Solution {
public:
    void func(string curr,string tiles,vector<int>&visited,unordered_set<string>&st){
        st.insert(curr);
        for(int i=0;i<tiles.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                func(curr+tiles[i],tiles,visited,st);
                visited[i]=0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        unordered_set<string>st;
        vector<int>visited(n,0);
        func("",tiles,visited,st);
        return st.size()-1;
    }
};
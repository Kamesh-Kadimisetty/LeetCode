class Solution {
public:
    int intersect(vector<vector<int>>& nums, int i, int j, int k) {
        int cnt = 0;
        unordered_set<int>st(nums[i].begin(), nums[i].end());         
        for(auto& x:nums[j]){
            if(st.count(x)){
                cnt++;
                st.erase(x);
                if(cnt >= k)return true;
            }
        }      
        return 0;
    }
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(intersect(properties,i,j,k)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int>visited(n+1,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};
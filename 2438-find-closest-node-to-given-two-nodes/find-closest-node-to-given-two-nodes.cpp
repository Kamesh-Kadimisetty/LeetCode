class Solution {
public:
    void dfs(int node,vector<int>&edges,vector<int>& dist){
        int x=0;
        while(node!=-1 && dist[node]==-1){
            dist[node]=x++;
            node=edges[node];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,-1);
        dfs(node1,edges,dist1);
        vector<int>dist2(n,-1);
        dfs(node2,edges,dist2);
        int minind=-1,mindist=INT_MAX;
        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                int distance=max(dist1[i],dist2[i]);
                if(distance<mindist){
                    minind=i;
                    mindist=distance;
                }
            }
        }
        return minind;
    }
};
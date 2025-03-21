class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_map<string,vector<string>>recptoing;
        unordered_map<string,int>indegree;
        unordered_map<string,vector<string>>ingtorecp;
        for(int i=0;i<n;i++){
            string recp=recipes[i];
            recptoing[recp]=ingredients[i];
            indegree[recp]=ingredients[i].size();
            for(auto it:ingredients[i]){
                ingtorecp[it].push_back(recp);
            }
        }
        queue<string>qu;
        for(auto it:supplies){
            qu.push(it);
        }
        vector<string>result;
        while(!qu.empty()){
            string curr=qu.front();
            qu.pop();
            if(recptoing.find(curr)!=recptoing.end()){
                result.push_back(curr);
            }
            if(ingtorecp.find(curr)!=ingtorecp.end()){
                for(auto it:ingtorecp[curr]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        qu.push(it);
                    }
                }
            }
        }
        return result;
    }
};
	
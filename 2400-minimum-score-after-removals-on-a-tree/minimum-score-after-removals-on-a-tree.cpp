class Solution {
public:
    int dp[1000] = {}, last[1000] = {};
int dfs(vector<int>& n, vector<vector<int>> &al, int i, int p, int &ids) {
    int id = ids++, res = n[i];
    for (auto j : al[i])
        if (j != p)
            res ^= dfs(n, al, j, i, ids);
    last[id] = ids;
    return dp[id] = res;    
}
int minimumScore(vector<int>& n, vector<vector<int>>& edges) {
    int ids = 0, res = INT_MAX;
    vector<vector<int>> al(n.size());
    for (auto &e :  edges) {
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);
    }
    int all = dfs(n, al, 0, -1, ids);    
    for (int i = 1; i < n.size(); ++i)
        for (int j = i + 1; j < n.size(); ++j) {
            int p1 = j < last[i] ? all ^ dp[i] : all ^ dp[i] ^ dp[j];
            int p2 = j < last[i] ? dp[i] ^ dp[j] : dp[i];
            res = min(res, max({p1, p2, dp[j]}) - min({p1, p2, dp[j]}));
        }
    return res;
}
};
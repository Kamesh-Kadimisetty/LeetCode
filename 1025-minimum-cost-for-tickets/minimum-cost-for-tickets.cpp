class Solution {
public:
    unordered_set<int> isTravelNeeded;    
    int solve(vector<int>& dp, vector<int>& days, vector<int>& costs, int currDay) {
        if (currDay > days[days.size() - 1]) {
            return 0;
        }        
        if (isTravelNeeded.find(currDay) == isTravelNeeded.end()) {
            return solve(dp, days, costs, currDay + 1);
        }
        if (dp[currDay] != -1) {
            return dp[currDay];
        }
        int oneDay = costs[0] + solve(dp, days, costs, currDay + 1);
        int sevenDay = costs[1] + solve(dp, days, costs, currDay + 7);
        int thirtyDay = costs[2] + solve(dp, days, costs, currDay + 30);
        return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);
        for (int day : days) {
            isTravelNeeded.insert(day);
        } 
        return solve(dp, days, costs, 1);
    }
};
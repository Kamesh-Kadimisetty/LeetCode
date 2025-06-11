class Solution {
public:
    int helper(int odd, int even, int k, vector<vector<int>>& prefSum){
        int typeMin[2][2];
        typeMin[0][0] = typeMin[0][1] = typeMin[1][1] = typeMin[1][0] = 1e5;
        int i = 0, j = k;
        auto& oddPref = prefSum[odd];
        auto& evenPref = prefSum[even];
        int ans = INT_MIN;
        int n = oddPref.size();
        while (j < n) {
            int oddAtj = oddPref[j], evenAtj = evenPref[j];
            int oddAti = oddPref[i], evenAti = evenPref[i];
            if (evenAtj != evenAti) {
                while (j - i >= k) {
                    int evenP = evenAti % 2, oddP = oddAti % 2;
                    (typeMin[oddP][evenP] = min(typeMin[oddP][evenP], oddAti - evenAti));
                    i++;
                    oddAti = oddPref[i], evenAti = evenPref[i];
                }
            }
            int maxAtj = oddAtj - evenAtj - typeMin[1 - (oddAtj % 2)][evenAtj % 2];
            ans = max(ans, maxAtj);
            j++;
        }
        return ans;
    }

    int maxDifference(string s, int k) {
        int n = s.size();
        vector<vector<int>> prefSum(5, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) prefSum[j][i + 1] = prefSum[j][i];
            prefSum[s[i] - '0'][i + 1]++;
        }
        int ans = INT_MIN;
        for (int i = 0; i < 5; i++) {
            if (!prefSum[i][n]) continue;
            for (int j = 0; j < 5; j++) {
                if (!prefSum[j][n] || i == j) continue;
                ans = max(ans, helper(i, j, k, prefSum));
            }
        }
        return ans;
    }
};
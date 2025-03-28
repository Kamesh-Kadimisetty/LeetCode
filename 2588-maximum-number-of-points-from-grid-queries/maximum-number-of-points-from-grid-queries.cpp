class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    vector<int> maxPoints(vector<vector<int>>& nums, vector<int>& queries) {
        int n = nums.size(), m = nums[0].size();
        vector<int> res(queries.size());
        vector<pair<int, int>> q(queries.size());
        for (int i = 0; i < queries.size(); i++) q[i] = {queries[i], i};
        sort(q.begin(), q.end());
        vector<vector<int>> visited(n, vector<int>(m, -1));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minh;
        minh.push({nums[0][0], {0, 0}});
        visited[0][0] = 1;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int count = 0;
        for (int i = 0; i < queries.size(); i++) {
            while (!minh.empty() && minh.top().first < q[i].first) {
                count++;
                int x = minh.top().second.first;
                int y = minh.top().second.second;
                minh.pop();
                for (int j = 0; j < 4; j++) {
                    int newx = x + dx[j];
                    int newy = y + dy[j];
                    if (valid(newx, newy, n, m) && visited[newx][newy] == -1) {
                        visited[newx][newy] = 1;
                        minh.push({nums[newx][newy], {newx, newy}});
                    }
                }
            }
            res[q[i].second] = count;
        }
        return res;
    }
};
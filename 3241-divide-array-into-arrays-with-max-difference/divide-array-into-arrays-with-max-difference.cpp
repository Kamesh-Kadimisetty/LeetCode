class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        vector<vector<int>>result;
        while(!pq.empty()){
            int size=3;
            vector<int>arr;
            int x=pq.top();
            while(size>0 && !pq.empty()){
                if(pq.top()-x>k) return {};
                arr.push_back(pq.top());
                pq.pop();
                size--;
            }
            result.push_back(arr);
        }
        return result;
    }
};
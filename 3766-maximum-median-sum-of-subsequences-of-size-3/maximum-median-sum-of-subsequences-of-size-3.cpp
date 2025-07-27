class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        long long sum=0;
        priority_queue<long long>pq(nums.begin(),nums.end());
        while(!pq.empty() && cnt<n/3){
            pq.pop();
            sum+=pq.top();
            pq.pop();
            cnt++;
        }
        return sum;
    }
};
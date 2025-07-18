class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long>mini;
        priority_queue<long long>pq;
        long long sum=0;
        for(int i=0;i<n/3;i++){
            pq.push(nums[i]);
            sum+=nums[i];
        }
        mini.push_back(sum);
        for(int i=n/3;i<(2*n)/3;i++){
            pq.push(nums[i]);
            sum-=pq.top();
            pq.pop();
            sum+=nums[i];
            mini.push_back(sum);
        }
        vector<long long>maxi;
        priority_queue<long long,vector<long long>,greater<long long>>pq1;
        sum=0;
        for(int i=n-1;i>n-1-(n/3);i--){
            pq1.push(nums[i]);
            sum+=nums[i];
        }
        maxi.push_back(sum);
        for(int i=(2*n)/3-1;i>=n/3;i--){
            pq1.push(nums[i]);
            sum-=pq1.top();
            pq1.pop();
            sum+=nums[i];
            maxi.push_back(sum);
        }
        reverse(maxi.begin(),maxi.end());
        long long result=LLONG_MAX;
        for(int i=0;i<mini.size();i++){
            result=min(result,mini[i]-maxi[i]);
        }
        return result;
    }
};
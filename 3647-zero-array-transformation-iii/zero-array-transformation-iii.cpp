class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        sort(queries.begin(),queries.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        priority_queue<int>pq;
        vector<int>arr(n+1,0);
        int ope=0,j=0;
        for(int i=0;i<n;i++){
            ope+=arr[i];
            while(j<queries.size() && queries[j][0]==i){
                pq.push(queries[j][1]);
                j++;
            }
            while(!pq.empty() && ope<nums[i] && pq.top()>=i){
                ope++;
                arr[pq.top()+1]-=1;
                pq.pop();
            }
            if(ope<nums[i]){
                return -1;
            }
        }
        return pq.size();
    }
};
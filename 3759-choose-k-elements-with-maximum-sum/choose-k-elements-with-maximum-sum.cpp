class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<long long>result(n,0);
        vector<pair<int,int>>arr; //nums1 i 
        for(int i=0;i<n;i++){
            arr.push_back({nums1[i],i});
        }
        sort(arr.begin(),arr.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            int ind=arr[i].second;
            while(j<i){
                int prev=arr[j].second;
                if(arr[j].first>=arr[i].first)break;
                pq.push(nums2[prev]);
                sum+=nums2[prev];
                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
                j++;
            }
            result[ind]=sum;
        }
        return result;
    }
};
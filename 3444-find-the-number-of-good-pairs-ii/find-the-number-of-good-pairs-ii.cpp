class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        long long pairs=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j*j<=nums1[i];j++){
                if(j*j==nums1[i]) mpp[j]++;
                else if(nums1[i]%j==0){
                    mpp[j]++;
                    mpp[nums1[i]/j]++;
                }
            }
        }
        for(auto it:nums2){
            pairs+=mpp[it*k];
        }
        return pairs;
    }
};
class FindSumPairs {
public:
    unordered_map<int,int>mpp1,mpp2;
    vector<int>nums;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto it:nums1) mpp1[it]++;
        for(auto it:nums2) mpp2[it]++;
        nums=nums2;
    }
    
    void add(int index, int val) {
        mpp2[nums[index]]--;
        if(mpp2[nums[index]]==0) mpp2.erase(nums[index]);
        int x=nums[index]+val;
        nums[index]=x;
        mpp2[x]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto it:mpp1){
            if(mpp2.find(tot-it.first)!=mpp2.end()){
                cnt+=(it.second)*mpp2[tot-it.first];
            }
        }
        return cnt;
    }
};
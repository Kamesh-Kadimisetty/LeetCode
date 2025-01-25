class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==key){
                mpp[nums[i+1]]++;
            }
        }
        int target=0,maxcnt=0;
        for(auto it:mpp){
            if(it.second>maxcnt){
                target=it.first;
                maxcnt=it.second;
            }
        }
        return target;
    }
};
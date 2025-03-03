class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>lesser;
        vector<int>greater;
        int cnt=0;
        for(auto it:nums){
            if(it>pivot){
                greater.push_back(it);
            }
            else if(it<pivot){
                lesser.push_back(it);
            }
            else{
                cnt++;
            }
        }
        while(cnt>0){
            lesser.push_back(pivot);
            cnt--;
        }
        for(auto it:greater){
            lesser.push_back(it);
        }
        return lesser;
    }
};
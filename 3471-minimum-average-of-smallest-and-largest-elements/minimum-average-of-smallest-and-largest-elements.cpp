class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double>averages;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            double avg=(nums.front()+nums.back())/2.0;
            averages.push_back(avg);
            nums.erase(nums.begin());
            nums.pop_back();
        }
        return *min_element(averages.begin(),averages.end());
    }
};
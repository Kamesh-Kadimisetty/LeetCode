class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0,count2=0;
        int candidate1=0,candidate2=0;
        for(auto it : nums){
            if(count1==0 && it!=candidate2){
                candidate1=it;
                count1++;
            }
            else if(count2==0 && it!=candidate1){
                candidate2=it;
                count2++;
            }
            else if(it==candidate1) count1++;
            else if(it==candidate2) count2++;
            else{
                count1--,count2--;
            }
        }
            vector<int>ans;
            count1=0,count2=0;
            for(auto it: nums){
                if(it==candidate1) count1++;
                if(it==candidate2) count2++;
            }

            if(count1>n/3) ans.push_back(candidate1);
            if(count2>n/3 && candidate1!=candidate2) ans.push_back(candidate2);
        return ans;
    }
};
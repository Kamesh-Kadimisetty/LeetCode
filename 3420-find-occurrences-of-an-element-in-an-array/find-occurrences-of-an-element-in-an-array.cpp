class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int count=1;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                mpp[count]=i;
                count++;
            }
        }
        for(int i=0;i<queries.size();i++){
            if(mpp.find(queries[i])!=mpp.end()){
                queries[i]=mpp[queries[i]];
            }
            else{
                queries[i]=-1;
            }
        }
        return queries;
    }
};
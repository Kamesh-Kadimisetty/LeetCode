class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mpp;
        int n=groupSizes.size();
        for(int i=0;i<n;i++){
            mpp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>result;
        for(auto it:mpp){
            int size=it.first;
            vector<int>persons=it.second;
            int m=persons.size();
            if(m==size){
                result.push_back(persons);
            }
            else{
                for(int i=0;i<m/size;i++){
                    vector<int>arr;
                    for(int j=(i*size);j<(i*size)+size;j++){
                        arr.push_back(persons[j]);
                    }
                    result.push_back(arr);
                }
            }
        }
        return result;
    }
};
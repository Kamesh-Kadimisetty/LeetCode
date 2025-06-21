class Solution {
public:
    int func(int minlimit,int maxlimit,vector<int>&arr){
        int total=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<minlimit) total+=arr[i];
            if(arr[i]>maxlimit) total+=(arr[i]-maxlimit);
        }
        return total;
    }
    int minimumDeletions(string word, int k) {
        int n=word.size(),i=0;
        vector<int>freq(26,0);
        for(auto it:word) freq[it-'a']++;
        vector<int>arr;
        for(auto it:freq){
            if(it!=0) arr.push_back(it);
        }
        int mindeletions=INT_MAX;
        for(int i=0;i<arr.size();i++){
            int maxlimit=arr[i]+k;
            int minlimit=arr[i];
            mindeletions=min(mindeletions,func(minlimit,maxlimit,arr));
        }
        return mindeletions;
    }
};
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n=tasks.size();
        sort(tasks.rbegin(),tasks.rend());
        sort(processorTime.begin(),processorTime.end());
        int result=INT_MIN;
        for(int i=0,j=0;i<n;i+=4){
            result=max(result,processorTime[j++]+tasks[i]);
        }
        return result;
    }
};
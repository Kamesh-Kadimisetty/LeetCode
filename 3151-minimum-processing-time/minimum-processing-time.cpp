class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end());
        sort(processorTime.rbegin(),processorTime.rend());
        int result=INT_MIN;
        for(int i=0;i<n;i+=4){
            int x=processorTime[i/4];
            for(int j=i;j<i+4;j++){
                result=max(result,x+tasks[j]);
            }
        }
        return result;
    }
};
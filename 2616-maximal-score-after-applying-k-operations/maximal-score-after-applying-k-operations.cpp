class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxheap(nums.begin(), nums.end());
        long long score=0;
        while(k>0){
            int maxele=maxheap.top();
            maxheap.pop();
            score+=maxele;
            maxheap.push(ceil(maxele/3.00));
            k--;
        }
        return score;
    }
};
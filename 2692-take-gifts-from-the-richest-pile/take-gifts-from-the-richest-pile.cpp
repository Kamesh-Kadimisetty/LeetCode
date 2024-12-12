class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum=0;
        int n=gifts.size();
        for(int i=0;i<k;i++){
            sort(gifts.begin(),gifts.end());
            gifts[n-1]=sqrt(gifts[n-1]);
        }
        sum=accumulate(gifts.begin(),gifts.end(),sum);
        return sum;
    }
};
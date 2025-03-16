class Solution {
public:
    bool ispossible(vector<int>& ranks, long long cars,long long time){
        for(auto it:ranks){
            if(time>=it){
                int numcars=floor(sqrt(time/it));
                cars-=numcars;
            }
        }
        return cars<=0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long minele=*min_element(ranks.begin(),ranks.end());
        long long low=1,high=minele*cars*cars;
        while(low<=high){
            long long mid=(low+high)/2;
            if(ispossible(ranks,(long long)cars,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
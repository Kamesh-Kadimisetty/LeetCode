class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int water=capacity,n=plants.size();
        int distance=0,i=0,pos=-1;
        while(i<n){
            if(water>=plants[i]){
                distance+=abs(pos-i);
                pos=i;
                water-=plants[i];
                if(i<n-1 && water>=plants[i+1]){
                    i++;
                    distance++;
                    pos=i;
                }
                if(i==n-1){
                    return distance;
                }
            }
            else{
                distance+=abs(pos+1);
                pos=-1;
                water=capacity;
                i++;
            }
        }
        return distance;
    }
};
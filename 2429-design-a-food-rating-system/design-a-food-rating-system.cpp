class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>>cusrating;
    unordered_map<string,int>foodrating;
    unordered_map<string,string>foodcus;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            foodrating[foods[i]]=ratings[i];
            foodcus[foods[i]]=cuisines[i];
            cusrating[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cus=foodcus[food];
        cusrating[cus].erase({-foodrating[food],food});
        cusrating[cus].insert({-newRating,food});
        foodrating[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return cusrating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 **/
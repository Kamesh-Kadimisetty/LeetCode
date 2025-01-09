int k1;
    bool comp(vector<int>&a,vector<int>&b){
        return a[k1]>b[k1];
    }
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        k1=k;
        sort(score.begin(),score.end(),comp);
        return score;
    }
};
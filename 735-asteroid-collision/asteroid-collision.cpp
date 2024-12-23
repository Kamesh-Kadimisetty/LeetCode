class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }
            else{
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i])){
                    st.pop_back();
                }
                if(st.empty() || st.back()<0){
                    st.push_back(asteroids[i]);
                    continue;
                }
                if(!st.empty()&& st.back()>0 && st.back()==abs(asteroids[i])){
                    st.pop_back();
                    continue;
                }
                if(st.back()<0){
                    st.push_back(asteroids[i]);
                    continue;
                }
            }
        }
        vector<int>result(st.begin(),st.end());
        return result;
    }
};
class MyCalendar {
public:
    vector<pair<int,int>> calender;    
    bool book(int start, int end) {
        for(const auto [s,e] : calender){
            if(start<e && s<end){
                return false;
            }
        }
        calender.emplace_back(start,end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
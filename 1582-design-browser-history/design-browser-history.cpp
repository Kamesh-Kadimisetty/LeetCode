class ListNode1{
    public:
    string data;
    ListNode1* next;
    ListNode1* back;
    ListNode1():data(""),next(NULL),back(NULL){};
    ListNode1(string x):data(x),next(NULL),back(NULL){};
    ListNode1(string x,ListNode1* a,ListNode1* b):data(x),next(a),back(b){};
    
};
class BrowserHistory {
public:
    ListNode1* currentpage;
    BrowserHistory(string homepage) {
        currentpage=new ListNode1(homepage);
    }
    
    void visit(string url) {
        ListNode1* newnode=new ListNode1(url);
        currentpage->next=newnode;
        newnode->back=currentpage;
        currentpage=currentpage->next;
    }
    
    string back(int steps) {
        while(steps){
            if(currentpage->back){
                currentpage=currentpage->back;
            }
            else{
                break;
            }
            steps--;
        }
        return currentpage->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(currentpage->next){
                currentpage=currentpage->next;
            }
            else{
                break;
            }
            steps--;
        }
        return currentpage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
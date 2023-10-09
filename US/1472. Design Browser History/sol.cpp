class BrowserHistory {
private:
    list<string> history;
    list<string>::iterator it;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        if (next(it) != history.end()){
            history.erase(next(it), history.end());
        }
        history.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(steps > 0 && it != history.begin()){
            it--;
            steps--;
        }
        return *it;
    }
    
    string forward(int steps) {
        auto lastone = prev(history.end());
        while(steps > 0 && it != lastone){
            it++;
            steps--;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

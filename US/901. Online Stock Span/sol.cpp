class StockSpanner {
private:
    vector<pair<int, int>> v;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        if (v.size() == 0){
            v.emplace_back(price, 1);
            return 1;
        }
        int n = v.size();
        int i = n-1;
        while (i >= 0){
            int prev_price = v[i].first;
            int prev_ret = v[i].second;
            if (price >= prev_price){
                i -= prev_ret;
            }else{
                v.emplace_back(price, n - i);
                return n - i;
            }
        }
        v.emplace_back(price, n + 1);
        return n+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

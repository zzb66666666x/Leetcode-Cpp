class StockPrice {
private:
    int latest;
    unordered_map<int, int> time2price;
    map<int, unordered_set<int>> price2time;
public:
    StockPrice() {
        latest = 0;
    }
    
    void update(int timestamp, int price) {
        if (timestamp > latest){
            time2price.emplace(timestamp, price);
            price2time[price].emplace(timestamp);
            latest = timestamp;
        }else{
            int oldprice = time2price[timestamp];
            if (price != oldprice){
                time2price[timestamp] = price;
                price2time[oldprice].erase(timestamp);
                if (price2time[oldprice].size() == 0){
                    price2time.erase(oldprice);
                }
                price2time[price].emplace(timestamp);
            }
        }
    }
    
    int current() {
        return time2price[latest];
    }
    
    int maximum() {
        auto it = price2time.end();
        it--;
        return it->first;
    }
    
    int minimum() {
        return price2time.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

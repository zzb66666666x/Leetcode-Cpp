class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, vector<string>> g;
        for (auto& tik : tickets){
            string& src = tik[0];
            string& dst = tik[1];
            if (g.count(src) == 0){
                g.emplace(src, (vector<string>){dst});
            }else{
                auto& v = g[src];
                v.emplace_back(dst);
            }
        }
        // traverse through g beginning with jfk
        vector<string> stations;
        if (g.find("JFK") == g.end()){
            return stations;
        }
        unordered_map<string, int> visited;
        for (auto& pair : g){
            sort(pair.second.begin(), pair.second.end());
            // debug
            // cout<<pair.first<<endl<<"    ";
            // for (auto& item: pair.second){
            //     cout<<item<<" ";
            // }
            // cout<<endl;
            // end of debug
            string src = pair.first;
            for (string& dst : pair.second){
                string key = src + dst;
                if (visited.find(key) == visited.end()){
                    visited[key] = 1;
                }else{
                    visited[key] ++;
                }
            }
        }
        dfs("JFK", g, stations, visited, 0, n);
        vector<string> ret;
        for (int i=stations.size()-1; i>=0; i--){
            ret.push_back(move(stations[i]));
        }
        return ret;
    }

    int dfs(string src, unordered_map<string, vector<string>>& g, vector<string>& stations, unordered_map<string, int>& visited, int used, int n){
        if (used == n){
            stations.push_back(move(src));
            return 1;
        }
        auto& v = g[src];
        for (auto& dst: v){
            string key = src + dst;
            // cout<<key<<endl;
            if (visited[key] <= 0){
                // cout<<"continue"<<endl;
                continue;
            }
            visited[key]--;
            int finish = dfs(dst, g, stations, visited, used+1, n);
            if (finish){    
                stations.push_back(move(src));
                return 1;
            }else{
                visited[key]++;
            }
        }
        return 0;
    }
};

class UnionFind{
private:
    vector<int> parent;
    vector<int> size;
    int count;
public:
    UnionFind(int n){
        count = n;
        parent.resize(n);
        size.resize(n);
        for (int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        // add path compression
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    int unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return count;
        if (size[rootX] > size[rootY]){
            swap(rootX, rootY);
        }
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
        count--;
        return count;
    }

    int connected(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        return rootX==rootY;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (i > 0) {
                    edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
            auto&& [x1, y1, v1] = e1;
            auto&& [x2, y2, v2] = e2;
            return v1 < v2;
        });
        UnionFind uf(m * n);
        int endId = m * n -1;
        for (auto& [x, y, d] : edges){
            uf.unite(x, y);
            if (uf.connected(0, endId)){
                return d;
            }
        }
        return 0;
    }
};

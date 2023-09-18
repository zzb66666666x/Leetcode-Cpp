// Method 2 helpers: 并查集
class DisjointSetUnion {
private:
    vector<int> f, rank;
    int n;

public:
    DisjointSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    int unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return true;
    }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {
    }
};

class Solution {
public:
    // Method 1: Prim Algorithm
    // int prim(vector<vector<int> >& points, int start) {
    //     int n = points.size();
    //     int res = 0;

    //     // 1. 邻接矩阵
    //     vector<vector<int> > g(n, vector<int>(n));
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    //             g[i][j] = g[j][i] = dist;
    //         }
    //     }
    //     // 记录V中的点到Vnew的最近距离
    //     vector<int> lowcost(n, INT_MAX);
    //     // 记录V中的点是否加入到了Vnew
    //     vector<int> v(n);
    //     // lowcost 和 v 可以优化成一个数组

    //     // 2. 先将start加入到Vnew
    //     v[start] = 1;
    //     for (int i = 0; i < n; i++) {
    //         if (i == start) continue;
    //         lowcost[i] = g[i][start];
    //     }

    //     // 3. 遍历剩余若干个未加入到Vnew的节点
    //     for (int _ = 1; _ < n; _++) {
    //         // 找出此时V中，离Vnew最近的点
    //         int minIdx = -1;
    //         int minVal = INT_MAX;
    //         for (int j = 0; j < n; j++) {
    //             if (v[j] == 0 && lowcost[j] < minVal) {
    //                 minIdx = j;
    //                 minVal = lowcost[j];
    //             }
    //         }
    //         // 将最近的点加入Vnew
    //         v[minIdx] = 1;
    //         res += minVal;

    //         // 更新集合V中剩余所有点的lowcost
    //         for (int j = 0; j < n; j++) {
    //             if (v[j] == 0 && g[j][minIdx] < lowcost[j]) {
    //                 lowcost[j] = g[j][minIdx];
    //             }
    //         }
    //     }
    //     return res;

    // }

    // int minCostConnectPoints(vector<vector<int>>& points) {
    //     return prim(points, 0);
    // }

    // Kruskal Algorithm + Union Find
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto dist = [&](int x, int y) -> int {
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };
        int n = points.size();
        DisjointSetUnion dsu(n);
        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(dist(i, j), i, j);
            }
        }
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int { return a.len < b.len; });
        int ret = 0, num = 1;
        for (auto& [len, x, y] : edges) {
            if (dsu.unionSet(x, y)) {
                ret += len;
                num++;
                if (num == n) {
                    break;
                }
            }
        }
        return ret;
    }
};

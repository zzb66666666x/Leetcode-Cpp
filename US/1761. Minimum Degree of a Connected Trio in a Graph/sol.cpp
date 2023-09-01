class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
	// 原图
	vector<unordered_set<int>> g(n);
	// 定向后的图
	vector<vector<int>> h(n);
	vector<int> degree(n);

	for (auto&& edge: edges) {
	    int x = edge[0] - 1, y = edge[1] - 1;
	    g[x].insert(y);
	    g[y].insert(x);
	    ++degree[x];
	    ++degree[y];
	}
	for (auto&& edge: edges) {
	    int x = edge[0] - 1, y = edge[1] - 1;
	    if (degree[x] < degree[y] || (degree[x] == degree[y] && x < y)) {
		h[x].push_back(y);
	    }
	    else {
		h[y].push_back(x);
	    }
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
	    for (int j: h[i]) {
		for (int k: h[j]) {
		    if (g[i].count(k)) {
			ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
		    }
		}
	    }
	}

	return ans == INT_MAX ? -1 : ans;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/minimum-degree-of-a-connected-trio-in-a-graph/solutions/2417898/yi-ge-tu-zhong-lian-tong-san-yuan-zu-de-wuv8o/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

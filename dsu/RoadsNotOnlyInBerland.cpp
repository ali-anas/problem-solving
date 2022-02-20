// link : https://codeforces.com/problemset/problem/25/D

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
	vector<int> rank, parent;
	vector<pair<int, int>> old_roads;
	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		old_roads.clear();
	}

	int Get(int node) {
		return parent[node] = (parent[node] == node) ? node : Get(parent[node]);
	}

	void Union(int node1, int node2) {
		int pnode1 = Get(node1);
		int pnode2 = Get(node2);

		if (pnode1 == pnode2) {
			old_roads.push_back({node1, node2});
			return;
		}
		if (rank[pnode1] == rank[pnode2]) rank[pnode1]++;
		if (rank[pnode1] > rank[pnode2]) parent[pnode2] = pnode1;
		else parent[pnode1] = pnode2;
		return;
	}
};

void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	file_i_o();
	int n, a, b;
	cin >> n;
	DSU dsu(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		dsu.Union(a, b);
	}

	vector<int> available_points;
	int component = 0, newRoads = 0;
	for (int i = 1; i <= n; i++) {
		if (dsu.parent[i] == i) {
			component++;
			available_points.push_back(i);
		}
	}

	newRoads = component - 1;


	for (int i = 0; i < newRoads; i++) {
		cout << dsu.old_roads[i].first << " " << dsu.old_roads[i].second << " " << available_points[i] << " " << available_points[i + 1] << endl;
	}
}
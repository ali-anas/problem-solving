#include <bits/stdc++.h>
using namespace std;

void file_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

/*
7 5
1 2
3 2
3 4
6 2
5 6

*/

void zero_one_bfs(vector<pair<int, int>> edges[], vector<int>& d) {
	d[1] = 0;
	deque<int> q;
	q.push_front(1);
	while(!q.empty()) {
		int v = q.front();
		q.pop_front();

		for(auto edge: edges[v]) {
			int u = edge.first;
			int w = edge.second;

			if(d[v] + w < d[u]) {
				d[u] = d[v] + w;

				if(w == 1) q.push_back(u);
				else q.push_front(u);
			} 
		}
	}
}

int main() {
    // file_io();
	// your code goes here
	int n, m, u, v;
	cin >> n >> m;
	vector<pair<int, int>> edges[n+1];
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		if (u == v) continue;
		edges[u].push_back(make_pair(v, 0));
		edges[v].push_back(make_pair(u, 1));
	}

	vector<int> distance(n+1, INT_MAX);
	zero_one_bfs(edges, distance);
	if(distance[n] == INT_MAX) cout << -1 << endl;
	else cout << distance[n] << endl;
	
	return 0;
}
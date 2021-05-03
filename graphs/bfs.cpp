#include <bits/stdc++.h>
using namespace std;


void bfs(const vector<vector<int>>& adj,const int& s,const int& n) {

	queue<int> q;
	vector<bool> visited(n);
	vector<int> d(n), p(n);

	q.push(s);
	visited[s] = true;
	p[s] = -1;
	while(!q.empty()) {
		int v = q.front();
		q.pop();

		// do something with current vertex
		cout << v << " ";

		while(int u: adj[v]) {
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
				p[u] = v;
			}
		}
	}

}

int main() {


	return 0;
}
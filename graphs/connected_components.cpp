#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000

vector<bool> used(MAXN);
vector<int> comp;
vector<vector<int>> comps;

void dfs(const vector<vector<int>>& adj, int v) {
	used[v] = true;
	comp.push_back(v);
	
	for(size_t i = 0; i < (int) adj[v].size(); i++) {
		int to = adj[v][i];
		if(!used[to]) {
			dfs(adj, to);
		}
	}
}

void find_components(const vector<vector<int>>& adj, int n) {
	for(int i = 0; i < n; i++) used[i] = false;

	comps.clear();
	for(int i = 0; i < n; i++) {
		if (!used[i]) {
			comp.clear();
			dfs(adj, i);
			comps.push_back(comp);
		}
	}

	cout << "total components: " << comps.size() << endl;
}

int main() {


	return 0;
}
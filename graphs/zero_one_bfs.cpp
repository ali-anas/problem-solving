#include <bits/stdc++.h>
using namespace std;

// void zero_one_bfs(const vector<pair<int, int>> edges[], vector<int>& distance, int start) {

// 	distance[start] = 0;
// 	deque<int> q;
// 	q.push_back(start);

// 	while(!q.empty()) {
// 		int curr = q.front();
// 		q.pop_front();

// 		for(int i = 0; i < edges[curr].size(); i++) {
// 			if(distance[edges[curr][i].first] > distance[curr] + edges[curr][i].second) {
// 				distance[edges[curr][i].first] =  distance[curr] + edges[curr][i].second;
			
// 				if(edges[curr][i].second == 0) {
// 					q.push_front(edges[curr][i].first);
// 				} else {
// 					q.push_back(edges[curr][i].first);
// 				}
// 			}
// 			cout << "Processing in for" << endl;
// 		}
// 		cout << "Processing in while" << endl;
// 	}
// }

void zero_one_bfs(const vector<pair<int, int>> edges[], vector<int>& d, int s) {
	d[s] = 0;
	deque<int> q;
	q.push_front(s);
	while(!q.empty()) {
		int v = q.front();
		q.pop_front();
		for(auto edge: edges[v]) {
			int u = edge.first;
			int w = edge.second;
			if(d[v] + w < d[u]) {
				d[u] = d[v] + w;
				if(w==1) q.push_back(u);
				else q.push_front(u);
			}
		}
	}
}


int main() {
	int v, e, w, v1, v2;
	cin >> v >> e;
	vector<pair<int, int>> edges[v];
	for(int i = 0; i< e; i++) {
		cin >> v1 >> v2 >> w;
		edges[v1].push_back(make_pair(v2, w));
		edges[v2].push_back(make_pair(v1, w));
	}

	vector<int> distance(v, INT_MAX);

	zero_one_bfs(edges, distance, 0);

	for(int d: distance) cout << d << " ";
	// for(int i = 0; i < v; i++) {
	// 	for(pair<int, int> p: edges[i]) {
	// 		cout << i << " " << p.first << " " << p.second << endl;
	// 	}
	// }

	return 0;
}
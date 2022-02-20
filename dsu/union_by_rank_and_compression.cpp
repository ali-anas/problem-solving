#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int Get(vector<int>&parent, int i) {
	return parent[i] = (parent[i] == i)? i : Get(parent, parent[i]);
}

void Union(vector<int>&parent, vector<int>& rank, ll a, ll b) {
	a = Get(parent, a); // get the leader element of a
	b = Get(parent, b); // get the leader element of b

	if(rank[a] == rank[b]) {
		rank[a]++;
	}
	if(rank[a] > rank[b]) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> parent(n+1);
	vector<int> rank(n+1, 0);

	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}

	while(m--) {
		string str;
		cin >> str;
		if(str == "union") {
			ll x, y;
			cin >> x >> y;
			Union(parent, rank, x, y);
		} else {
			ll x;
			cin >> x;
			cout << Get(parent, x) << endl;
		}
	}
}
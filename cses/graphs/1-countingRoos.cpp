// Problem Link - https://cses.fi/problemset/task/1192/
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n)			n.begin(), n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str, char ch) {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
#endif
}

void captureAllNeighbors(vector<vector<char>>& adj, vector<vector<int>>& vis, const int& n, const int& m, int start_i, int start_j) {
	vis[start_i][start_j] = 1;
	int neighbour_xs[4] = {1, -1, 0, 0};
	int neighbour_ys[4] = {0, 0, 1, -1};

	for (int i = 0; i < 4; i++) {
		int new_x = start_i + neighbour_xs[i];
		int new_y = start_j + neighbour_ys[i];

		if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && !vis[new_x][new_y] && adj[new_x][new_y] == '.') {
			captureAllNeighbors(adj, vis, n, m, new_x, new_y);
		}
	}
}

void solve() {
	// write your code here.
	int n, m;
	cin >> n >> m;
	vector<vector<char>> adj(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj[i][j];
		}
	}

	int cnt = 0;
	vector<vector<int>> vis(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (adj[i][j] == '.' && !vis[i][j]) {
				captureAllNeighbors(adj, vis, n, m, i, j);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
}

int main(int argc, char const *argv[]) {
	file_i_o();

	// int t;
	// cin >> t;
	// while (t--)
	solve();

	return 0;
}
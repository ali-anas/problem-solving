// Problem Link -
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

int prims(vector<pii> adj[], int n) {
	set<vi> minw_node; // {min_weight, node}
	vector<bool> used(n + 1);
	vi minw(n + 1, inf);
	int ans = 0;

	minw_node.insert({0, 1});
	minw[1] = 0;

	for (int i = 1; i <= n; i++) {
		if (minw_node.empty())
			return -1;

		int cur = (*minw_node.begin())[1];
		used[cur] = 1;
		ans += minw[cur];
		minw_node.erase(minw_node.begin());

		for (auto &e : adj[cur]) {
			int v = e.ff, w = e.ss;

			if (used[v]) {
				// edge between both visited nodes
				continue;
			}

			if (w < minw[v]) {
				minw_node.erase({minw[v], v});
				minw[v] = w;
				minw_node.insert({minw[v], v});
			}
		}
	}

	return ans;
}

void solve() {
	// write your code here.
	int n, m; cin >> n >> m;
	vector<pii> adj[n + 1];

	loop(i, 0, m - 1) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].pb(make_pair(v, w));
		adj[v].pb(make_pair(u, w));
	}
	cout << prims(adj, n) << endl;
}

int main(int argc, char const *argv[]) {
	file_i_o();

	// int t;
	// cin >> t;
	// while (t--)
	solve();

	return 0;
}
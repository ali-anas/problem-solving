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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


vector<vector<int>> adj, rev_adj;
vector<int> order, component;
vector<bool> used;

void dfs1(int v) {
	used[v] = true;
	for (auto u : adj[v]) {
		if (!used[u])
			dfs1(u);
	}
	order.pb(v);
}

void dfs2(int v) {
	used[v] = true;
	component.pb(v);
	for (auto u : rev_adj[v]) {
		if (!used[u])
			dfs2(u);
	}
}


// Complexity => O(n+m) -> two dfs
void solve() {
	// write your code here.
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	rev_adj.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		rev_adj[b].pb(a);
	}

	used.assign(n + 1, false);
	loop(i, 1, n) {
		if (!used[i]) {
			dfs1(i);
		}
	}

	used.assign(n + 1, false);
	reverse(all(order));

	for (auto v : order) {
		if (!used[v]) {
			dfs2(v);
			// process component
			for (int node : component) {
				cout << node << " ";
			} cout << endl;
			component.clear();
		}
	}
}

int main(int argc, char const *argv[]) {
	file_i_o();

	// int t;
	// cin >> t;
	// while(t--)
	solve();

	return 0;
}
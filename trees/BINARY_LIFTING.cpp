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
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

vi depth;
int LOG;

void create_pointers(vi edges[], vector<vector<int>> &up, int u, int p) {
	up[u][0] = p;
	loop(i, 1, LOG) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}

	for (auto v : edges[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			create_pointers(edges, up, v, u);
		}
	}

}

int lca(vector<vector<int>> &up, int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);

	for (int i = LOG; i >= 0; i--) {
		int a_dash = up[a][i];
		if (depth[a_dash] >= depth[b])
			a = a_dash;
	}

	if (a == b) return a;

	for (int i = LOG; i >= 0; i--) {
		if (up[a][i] != up[b][i]) {
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

void solve() {
	// write your code here.

	int n, u, v;
	cin >> n;
	vi edges[n + 1];

	LOG = (int)ceil(log2(n));
	vector<vector<int>> up(n + 1, vector<int>(LOG + 1));
	depth.resize(n + 1);

	loop(i, 0, n - 2) {
		cin >> u >> v;
		edges[u].pb(v);
		edges[v].pb(u);
	}

	create_pointers(edges, up, 1, 1);
	// cout << "Created pointers" << endl;


}

int main(int argc, char const *argv[]) {
	file_i_o();

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
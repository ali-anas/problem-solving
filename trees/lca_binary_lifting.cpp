// Problem - Let G be a tree.
// For every query of the form (u, v) we want to find
// the lowest common ancestor of the nodes u and v
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

// vector<int> tree[200001];
// int up[200001][20]; // int up[n][20]

vector<vector<int>> up;
vector<int> depth;
int LOG;

void create_jump_pointers(int n, vector<int>& parent) {
	LOG = 0;
	while ((1 << LOG) <= n) {
		LOG++;
	}

	up = vector<vector<int>>(n, vector<int>(LOG));
	depth =  vector<int>(n);
	// up[v][j] is 2^j -th ancestor of node v
	for (int v = 0; v < n; v++) {
		up[v][0] = parent[v];
		if (v != 0) {
			depth[v] = depth[parent[v]] + 1;
		}
		for (int j = 1; j < LOG; j++) {
			up[v][j] = up[up[v][j - 1]][j - 1];
		}
	}

	cout << "jump pointers created" << endl;
}

int lca(int u, int v, vector<int>& parent) {
	if (depth[v] < depth[u]) {
		swap(u, v);
	}

	for (int k = LOG - 1; k >= 0; k--) {
		int v_dash = up[v][k];
		if (depth[v_dash] >= depth[u]) {
			v = v_dash;
		}
	}

	// special case
	if (u == v) return u;

	// find highest u' and v' such that u' != v'
	// by binary search
	// lca would be parent of u
	for (int k = LOG - 1; k >= 0; k--) {
		int u_dash = up[u][k];
		int v_dash = up[v][k];
		if (u_dash != v_dash) {
			u = u_dash;
			v = v_dash;
		}
	}
	return parent[u];
}

void create_parent(vector<int> tree[], vector<int>& parent) {
	parent[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int par = q.front();
		q.pop();
		for (int node : tree[par]) {
			if (node != par) {
				parent[node] = par;
				q.push(node);
			}
		}
	}

	cout << "parent created" << endl;
}

void solve() {
	// write your code here.
	int n, u, v, x, y;
	cin >> n >> x >> y;
	vector<int> tree[n];
	vector<int> parent(n);
	loop(i, 1, n - 1) {
		cin >> u >> v;
		tree[u - 1].push_back(v - 1);
		tree[v - 1].push_back(u - 1);
	}

	create_parent(tree, parent);
	create_jump_pointers(n, parent);
	cout << lca(x - 1, y - 1, parent);
}

int main(int argc, char const *argv[]) {
	// file_i_o(s);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
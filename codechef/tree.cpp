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

int n, x;
vi ans, val_assigned;
vector<pii> childs;

bool cmp(const pii &a, const pii &b) {
	return a.ff > b.ff;
}

void dfs(vi adj[], ll curr, ll par = -1) {
	for (auto x : adj[curr]) {
		if (x == par) {
			continue;
		}
		dfs(adj, x, curr);
	}

	childs.clear();
	for (auto x : adj[curr]) {
		if (x != par) {
			childs.pb(make_pair(ans[x], x)); // {whole_subtree_ans, node}
		}
	}

	sort(all(childs), cmp); //nlogn

	int value = 1;
	for (auto child : childs) {
		val_assigned[child.ss] = value++;
	}

	for (auto x : adj[curr]) {
		if (x != par) {
			ans[curr] += val_assigned[x] * ans[x];
		}
	}
}

void solve() {
	cin >> n >> x;

	int u, v;
	vi adj[n + 1];
	loop(i, 0, n - 2) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ans.assign(n + 1, 1), val_assigned.assign(n + 1, 0);

	dfs(adj, 1);

	cout << (ans[1] % mod * x) % mod << endl;

}

int main(int argc, char const *argv[]) {
	file_i_o();

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
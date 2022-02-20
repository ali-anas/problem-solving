// Problem Link - to check if a graph is bipartite or not.
// can also be used to detect odd length cycle in graph.
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

// color = 0 (unvisited)
// color = 1 (visited with color 1)
// color = 2 (visited with color 2)


// check if odd cycle is present
// at some point 2 node will have same color in odd cycle
bool isBipartite = true;
void checkOddLengthCycle(int node, int color, vector<int> &vis, vector<int> adj[]) {
	vis[node] = color;
	for (auto to : adj[node]) {
		if (vis[to] == 0) {
			checkOddLengthCycle(to, 3 - color, vis, adj);
		}
		else if (vis[node] == vis[to]) {
			isBipartite = false;
		}
	}
	return ;
}

int main(int argc, char const *argv[]) {
	file_i_o();
	int n, e, u, v;
	cin >> n >> e;
	vector<int> adj[n + 1];
	for (int i = 0; i < e; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			checkOddLengthCycle(i, 1, vis, adj);
		}
	}

	if (isBipartite) {
		for (int i = 1; i <= n; i++) {
			cout << vis[i] << " ";
		}
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
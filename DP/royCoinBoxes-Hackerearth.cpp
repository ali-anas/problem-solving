// Problem Link - https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
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

void solve() {
	// write your code here.

}

ll s[1000005], e[1000005], dp[1000005], coins[1000005];

int main(int argc, char const *argv[]) {
	file_i_o();

	for (int i = 0; i < 1000005; i++) {
		s[i] = e[i] = dp[i] = coins[i] = 0;
	}

	int n, m;
	cin >> n >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		s[l]++;
		e[r]++;
	}

	dp[1] = s[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + s[i] - e[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		coins[dp[i]]++;
	}

	for (int i = n - 1; i >= 1; i--) {
		coins[i] = coins[i] + coins[i + 1];
	}

	ll q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << coins[x] << endl;
	}
	return 0;
}
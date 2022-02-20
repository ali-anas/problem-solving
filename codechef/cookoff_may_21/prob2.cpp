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

void solve() {
	// write your code here.
	ll n, k; cin >> n >> k;
	ll *a = new ll[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];

	unordered_map<ll, pii> u;
	ll sum = 0;
	loop(i, 1, k) {
		sum += a[i];
	}
	u[sum].ff = k;
	u[sum].ss = k;

	int start = 1;
	int curr = k + 1;

	while (curr <= n) {
		ll prev_start = start;

		sum -= a[start];
		start++;
		sum += a[curr];
		if (a[prev_start] == a[curr] && u[sum].ff > 1) {
			u[sum].ff++;
		} else if (u[sum].ff > 1) {
			u[sum].ff += min(k, curr - u[sum].ss);
		} else {
			u[sum].ff += k;
		}
		u[sum].ss = curr;
		curr++;
	}

	ll max_same = 0;
	for (auto it = u.begin(); it != u.end(); it++) {
		max_same = max(max_same, it -> second.ff);
		cout << it -> ff << " " << it -> ss.ff  << " " << it -> ss.ss << endl;
	}

	// if (u.size() == 1) {
	// 	cout << 0 << endl;
	// 	return;
	// }

	cout << n - max_same << endl;
	delete []a;


}

int main(int argc, char const *argv[]) {
	file_i_o();

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
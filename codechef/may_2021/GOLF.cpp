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
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


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

bool b_search(ll start, ll end, ll k, ll x, ll n) {
	while(start <= end) {
		ll m = mid(start, end);
		// cout << "mid: " << m << endl;

		ll index = ((n+1)-(m*k));
		// cout << "index" << index << endl;
		if(index == x){
			return true;
		}
		if(index > x) start = m+1;
		else end=m-1;
	}
	return false;
}

// bool b_search(ll start, ll end, ll k, ll x) {
// 	while(start < end) {
// 		ll m = mid(start, end);
// 		ll index = m*k;
// 		if(index == x) {
// 			return true;
// 		}
// 		if(index > x) end = m-1;
// 		else start = m+1;
// 	}

// 	return false;
// }

void solve() {
	// write your code here.
	ll n,x,k;
	cin>>n>>x>>k;
	if(x%k == 0) {
		cout << "YES" << endl;
		return;
	}
	ll times = (n/k);
	if (b_search(0, times, k, x, n)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}

int main(int argc, char const *argv[]) {
	// file_i_o();

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
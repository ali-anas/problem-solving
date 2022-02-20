// Problem Link - https://www.spoj.com/problems/CPCRC1C/
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

ll pow_10(int p) {
	ll result = 1;
	loop(i, 1, p) {
		result *= 10;
	}
	return result;
}

ll sumOfDigits(ll num) {
	// base case
	if (num / 10 == 0) {
		return (num * (num + 1)) / 2;
	}
	string s = to_string(num);
	int n = s.size();

	ll pown_1 = pow_10(n - 1);

	int firstDigit = num / pown_1;

	ll contribution = pow_10(n - 2) * 45 * (n - 1);

	ll result = 0;
	loop(i, 0, firstDigit - 1) {
		result += (i * pown_1 + contribution);
	}

	int rest_nos = num % pown_1;
	result += firstDigit * (rest_nos + 1);
	result += sumOfDigits(rest_nos);
	return result;
}

void solve() {
	// write your code here.
	ll num;
	cin >> num;
	cout << sumOfDigits(num) << endl;
}

int main(int argc, char const *argv[]) {
	file_i_o();

	// int t;
	// cin >> t;
	// while (t--)
	// 	solve();
	ll a, b;
	while (true) {
		cin >> a >> b;
		if (a == -1 and b == -1) break;
		ll x = sumOfDigits(b);
		ll y = sumOfDigits(a - 1);
		cout << x - y << endl;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int
#define ld long double
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll> >
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)
#define loop(a,b) for(int i=(a);i<=(b);i++)
#define looprev(a,b) for(int i=(a);i>=(b);i++)
#define mpii unordered_map<int, int>
#define mpll unordered_map<ll, ll>

void file_io() {
	#ifndef ONLINE_JUDGE
		freopen("../../input.txt", "r", stdin);
		freopen("../../output.txt", "w", stdout);
	#endif
}

void a() {
	// write your code here
	int n;
	cin >> n;
	if ( n % 7 == 0) cout << n << endl;
	else {
		int ans = n;
		for(int i = 0; i <= 9; i++) {
			if ((n - (n % 10) + i) % 7 == 0)
				ans = n - n%10 + i;
		}
		cout << ans << endl;
	} 
}

void b() {
	string s;
	cin >> s;
	int zeroCount = 0, oneCount = 0;

	for(char& ch: s) {
		if ( ch == '0') zeroCount++;
		else oneCount++;
	}

	if (zeroCount == oneCount) {
		if (zeroCount > 1) {
			cout << zeroCount - 1 << endl;
			return;
		}
		cout << 0 << endl;
		return;
	}
	cout << min(zeroCount, oneCount) << endl;
}

void c() {
	ll hc, dc, hm, dm, k, inc_d , inc_h;
	cin >> hc >> dc >> hm >> dm >> k >> inc_d >> inc_h;

	for(int h = 0; h <= k; h++) {
		ll thc = hc + (h * inc_h);
		ll tmc = thc / dm;
		if ( thc % dm != 0) tmc++;

		ll tdc = dc + (k - h)*inc_d;

		ll tcm = hm / tdc;

		if(hm % tdc != 0) tcm++;

		if (tcm <= tmc) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
	return;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	file_io();
	int t;
	cin >> t;
	while(t--) c();
	return 0;
}
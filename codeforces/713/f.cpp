#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define for0n(i, n) for(int i = 0; i < int(n); i++)
#define forxn(i, x, n) for(int i = x; i < int(n); i++)
#define mpii unordered_map<int, int>
#define mpll unordered_map<ll, ll>

void solve() {
	// write your code here
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	vector<int> b(n-1);

	for(int &x: a) {
		cin >> x;
	}
	for(int &x: b) cin >> x;

	b.push_back(0);
	ll ans = 1e18;
	ll curr = 0;
	ll bal = 0;

	for(int i = 0; i < n; i++) {
		ans = min(ans, curr + max(0ll, c-bal+a[i]-1)/a[i]);
		ll newDays = max(0ll, b[i] - bal + a[i] -1) / a[i];
		curr += newDays + 1;
		bal += a[i] * newDays - b[i];
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
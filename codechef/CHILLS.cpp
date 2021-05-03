#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int &ai: a) cin >> ai;

	int start1 = a[n/2] - k/2;
	int start2 = a[n/2 - 1] - k/2;
	int ans = 1e18;

	for(int hill1: {start1, start2}) {
		int hill2 = hill1 + k - 1;
		int dist = 0;
		for(int ai: a) dist = max(abs(hill1 - ai), abs(hill2 - ai));
		ans = min(ans, dist);
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while(t--) solve();

	return 0;
}
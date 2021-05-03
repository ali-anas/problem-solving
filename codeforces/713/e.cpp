#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forin(i,s, n) for(int i = s; i < int(n); i++)

void no() {
	cout << -1 << endl;
}

int low(int k) {
	return (k * (k+1))/2;
}

int high(int n, int k) {
	return (k*(((2 * n) + 1)-k))/2;
}

void solve(){
	// write your code here
	int n, l, r, s;
	cin >> n >> l >> r >> s;

	int range = r-l+1;
	int ls = low(range);
	int hs = high(n, range);

	if(s > hs || s < ls) {
		no();
		return;
	}

	int curr = l;

	set<int> remaining;
	for(int i = 1; i<= n; i++) remaining.insert(i);

	vector<int> ans(n+1);
	for(int i = n; i > 0; i--) {
		if(high(i, range) >=s && s-i >= low(range-1)) {
			ans[curr] = i;
			remaining.erase(remaining.find(i));
			s -= i;
			range--;
			curr++;
		}
	}

	if(s > 0) {
		no();
		return;
	}

	set<int>::iterator it;
	for(int i = 1; i < l; i++) {
		it = remaining.begin();
		ans[i] = *it;
		remaining.erase(it);
	}

	for(int i = r+1; i <= n; i++) {
		it = remaining.begin();
		ans[i] = *it;
		remaining.erase(it);
	}

	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)

void no() {
	cout << "-1" << endl;
}

void solve() {
	int a, b; cin >> a>>b;
	string s; cin >> s;
	int n = (int)s.size();

	if((a+b) != n) {
		cout << -1 << endl;
		return;
	}

	for(int times = 0; times < 2; times++) {
		forn(i, n) {
			int j = n-i-1;
			if(s[i] != '?') {
				if(s[j] == '?') {
					s[j] = s[i];
				} else if(s[i] != s[j]) {
					no();
					return;
				}
			}
		}
		reverse(s.begin(), s.end());
	}

	a -= count(s.begin(), s.end(), '0');
	b -= count(s.begin(), s.end(), '1');
	int q = count(s.begin(), s.end(), '?');

	bool emptyMid = ((n%2 == 1) && s[n/2] == '?');

	if(a < 0 || b < 0 || a+b != q || (emptyMid && a%2 ==0 && b%2 == 0)) {
		no();
		return;
	}

	if(a %2 == 1 || b%2 == 1) {
		int i = n/2;
		if(s[i] != '?') {
			no();
			return;
		}

		s[i] = (a%2 == 1? '0' : '1');
		if(a%2 == 1) {
			a--;
		} else {
			b--;
		}
	}

	if(a%2 == 1 || b%2 == 1) {
		no();
		return;
	}

	forn(i, n) {
		if(s[i] == '?') {
			int j = n-i-1;
			if(a > 0) {
				s[i] = s[j] = '0';
				a-=2;
			} else {
				s[i] = s[j] = '1';
				b-=2;
			}
		}
	}
	cout << s << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
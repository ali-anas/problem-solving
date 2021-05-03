#include <bits/stdc++.h>
using namespace std;

void file_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int main() {
    // file_io();
	// your code goes here
	
	int t;
	cin >> t;
	while(t--) {
		int n, m, x, y, x_count = 0, y_count = 0;
		string s;
		cin >> n >> m >> x >> y;
		for(int i = 0; i < n; i++) {
			cin >> s;
			for(int j = 0; j < s.size(); j++) {
				if(s[j] == 'F') x_count++;
				else if(s[j] == 'P') y_count++;
			}
			if(x_count >= x) cout << 1;
			else if(x_count == (x-1) && y_count >= y) cout << 1;
			else cout << 0;
			x_count = 0;
			y_count = 0;
		}
		cout << endl;
	}
	
	return 0;
}
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


void solve1() {
	// write your code here
	long long int n, x;
	cin >> n;
	set<long long int> freq;
	for(int i = 0; i < n; i++) {
		cin >> x;
		freq.insert(x);
	}

	cout << freq.size() << "\n";

}

void solve2() {
	long long int n, m, k;
	cin >> n >> m >> k;

	vector<ll> desired(n), actual(m);
	for(auto &x : desired) cin >> x;
	for(auto &x : actual) cin >> x;

	sort(all(desired));
	sort(all(actual));

	long long int i = 0, j = 0;

	long long int count = 0;


	while(i < n && j < m) {
		long long acceptable_min = desired[i] - k;
		long long acceptable_max = desired[i] + k;

		if(actual[j] > acceptable_max) {
			i++;
		} else if (actual[j] < acceptable_min) {
			j++;
		} else {
			count++;
			i++;
			j++;
		}
	}

	cout << count << "\n";
}

void solve3() {
	int n, x;
	cin >> n >> x;
	vector<ll> arr(n);
	for(auto &x: arr) cin >> x;

	sort(all(arr));
	int i = 0, j = arr.size() - 1;
	int count = 0;

	while( i <= j) {
		if( i == j) {
			count++;
			i++;
			j--;
			continue;
		}
		ll sum = arr[i] + arr[j];
		if (sum <= x) {
			i++;
			j--;
			count++;
		}
		else if (sum > x) {
			j--;
			count++;
		} else {
			i++;
		}
	}

	cout << count << "\n";
}

int findByBSearch(vector<ll>& v, ll toFind, vector<int>& vis) {
	int low = 0;
	int high = v.size()-1;

	int ans = -1;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(v[mid] <= toFind) {
			if(!vis[mid]) ans = mid;
			low = mid + 1;
		} else {
			high = mid-1;
		}
	}



	if(ans != -1) vis[ans] = 1;

	return ans;
}

void solve4() {
	int n, m;
	cin >> n >> m;

	vector<ll> prices(n), receiving(m);
	vector<int> vis(n, 0);
	for(auto &p : prices) cin >> p;
	for(auto &r : receiving) cin >> r;

	sort(all(prices));

	for(int i = 0; i < m; i++) {
		ll r = receiving[i];
		int index = findByBSearch(prices, r, vis);
		cout << (index == -1 ? -1 : prices[index]);
		cout << "\n";
	} 
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve4();
	return 0;
}
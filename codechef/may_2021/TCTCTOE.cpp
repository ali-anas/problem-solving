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


bool isWinning(char triplet[8][3], char c) {
	for(int i = 0; i < 8; i++) {
		if(triplet[i][0] == c &&
			triplet[i][1] == c &&
			triplet[i][2] == c)
			return true;
	}
	return false;
}


void solve() {
	// write your code here.
	string arr[3];
	loop(i, 0,2) cin >> arr[i];
	char triplet[8][3];
	int xCount = 0, oCount = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			triplet[i][j] = arr[i][j];
			if(arr[i][j] == 'X') xCount++;
			if(arr[i][j] == 'O') oCount++;
		}
	}

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			triplet[3+i][j] = arr[j][i];
		}
	}

	for(int i = 0; i < 3; i++) {
		triplet[6][i] = arr[i][i];
	}

	for(int i = 0; i < 3; i++) {
		triplet[7][i] = arr[i][3-i-1];
	}

	if(xCount == oCount || xCount == oCount+1) {
		if(isWinning(triplet, 'O')) {
			if(isWinning(triplet, 'X')) {
				// not reachable
				cout << "3" << endl;
				return;
			}
			if (xCount == oCount) {
				// '0' is winning
				cout << "1" << endl;
				return;
			} else {
				// not reachable
				cout << "3" << endl;
				return;
			}
		}

		if(isWinning(triplet, 'X')) {
			if( xCount != oCount+1) {
				cout << "3" << endl;
			} else {
				cout << "1" << endl;
			}
			return;
		}


		// reachable and game will continue for at-least
		// one more step.
		if(xCount + oCount < 9) {
			cout << "2" <<endl;
			return;
		}

		// reachable but no one is winning
		cout << "1" << endl;
		return;
	}
	
	cout << "3" << endl;
	return;
}

int main(int argc, char const *argv[]) {
	// file_i_o();

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
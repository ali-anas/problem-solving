// Problem Link - https://codeforces.com/problemset/problem/1263/D
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

ll Get(vi &parent, ll a) {
    return parent[a] = (parent[a] == a? a : Get(parent, parent[a]));
}

void Union(vi &rank, vi &parent, ll a, ll b) {
    a = Get(parent, a);
    b = Get(parent, b);
    if(rank[a] == rank[b]) {
        rank[a]++;
    }
    if(rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

void solve() {
    // write your code here.
    int n;
    cin>>n;
    vi parent(27);
    vi rank(27, 1);
    vector<bool> total(26, false);
    vector<bool> current(26, false);
    loop(i,0,26) parent[i] = i;

    while(n--) {
        string str;
        cin>>str;
        loop(i, 0, 25) current[i] = false;
        for(char ch: str) {
            current[ch-'a'] = true;
        }

        loop(i, 0, 25) {
            if(current[i]) {
                total[i] = true;
                Union(rank, parent, str[0]-'a', i);
            }
        }
    }

    ll count = 0;
    loop(i, 0, 25) {
        if(total[i] and Get(parent, i) == i) count++;
    }
    cout<<count<<endl;
}

int main(int argc, char const *argv[]) {
    // file_i_o();

    // int t;
    // cin >> t;
    // while(t--)
    solve();

    return 0;
}
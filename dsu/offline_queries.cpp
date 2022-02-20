// Problem Link - Given an Undirected graph & some operations
// cut(a,b) - remove edge a, b
// get(a,b) - tell whether a&b are in same connected components or not
// each edge should be cut at-least once

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
#define all(n)          n.begin(), n.end()
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

int Get(vi &parent, int a) {
    return parent[a] = (parent[a] == a) ? a : Get(parent, parent[a]);
}

void Union(vi &parent, vi &rank, int a, int b) {
    a = Get(parent, a);
    b = Get(parent, b);

    if(rank[a] == rank[b]) rank[a]++;
    if(rank[a] > rank[b]) parent[b] = a;
    else parent[a] = b;
}

void solve() {
    // write your code here.
    int n, m, k;
    cin>>n>>m>>k;
    vi parent(n+1);
    vi rank(n+1, 1);
    loop(i,0,n) parent[i]=i;
    loop(i,0,m-1) {
        int a,b;
        cin>>a>>b; // take edges(no need to create graph if all edges are cut at-least once)
    }
    vector<pair<int, int>> qval(k);
    vector<int> qtype(k);
    loop(i, 0, k-1) {
        string str;
        cin>>str;
        int a,b;
        cin>>a>>b;
        qval[i] = {a,b};
        if(str == "cut") {
            qtype[i] = 1;
        } else {
            qtype[i] = 2;
        }
    }

    reverse(all(qtype));
    reverse(all(qval));

    vs results;
    loop(i,0,k-1){
        if(qtype[i]==1) {
            Union(parent, rank, qval[i].ff, qval[i].ss);
        } else {
            int a = Get(parent, qval[i].ff);
            int b = Get(parent, qval[i].ss);
            if(a != b) {
                results.pb("NO");
            } else {
                results.pb("YES");
            }
        }
    }

    reverse(all(results));
    logarr(results, 0, results.size()-1);
}

int main(int argc, char const *argv[]) {
    // file_i_o();

    // int t;
    // cin >> t;
    // while(t--) 
    solve();

    return 0;
}
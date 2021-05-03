#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 10;
const int Q = 2e5 + 10;
int A[N], rev[N], cnt[N];

struct Query{
	int idx, l, r, lb, rb;
} q[Q];

int compressed_val;
int ans[Q], curr_ans;

void add_element(int x) {
	if (++cnt[A[x]] == 1) {
		curr_ans += 1;
	}
}

void remove_element(int x) {
	if(--cnt[A[x]] == 0) {
		curr_ans -= 1;
	}
}

bool cmp(Query a, Query b) {
	return (a.lb < b.lb) || (a.lb == b.lb && a.r < b.rb);
}


int main() {
	// Read Input
	int n;
	scanf("%d", &n);
	int block = max(1, int(pow(n, 1.0 / 2.0)));
	map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		scanf("%d", A + i);
		mp[A[i]];
	}

	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		q[i] = {i, x, y, x / block, y / block};
	}

	// Coordinate compression.
	// 1 <= A[i] <= 1e9 --> 1 <= A[i] <= N?
	// 2, 5, 10 --> 1, 2, 3
	// 2 -- 1, 5 --> 2, 10 --> 3
	for(auto &it: mp) {
		it.second = +compressed_val;
		rev[compressed_val] = it.first;
	}
	for (int i = 1; i <= n; i++) {
		A[i] = mp[A[i]];
	}

	// Assume 1 <= A[i] <= 1e5
	// Sort the queries.
	sort(q+1, q+m+1, cmp);

	//Answer the queries.
	for(int i = 1, L = 1, R = 0; i <= m; i++) {
		// Total cost of all 4 loops : |L2 - L1| + |R2 - R1|
		while(R < q[i].r) add_element(++R);
		while(L > q[i].l) add_element(--L);
		while(R > q[i].r) add_element(R--);
		while(L < q[i].l) add_element(L++);
		ans[q[i].idx] = curr_ans;
	}
	for(int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
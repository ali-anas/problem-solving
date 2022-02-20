#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

class SegTree {
	vector<int> tree;
	int n;
public:

	SegTree(int _n) {
		tree.resize(4 * _n);
		this->n = _n;
	}

	void buildHelper(int index, int tl, int tr, vector<int> &arr) {
		if (tl == tr) {
			tree[index] = arr[tl];
			// cout << "index: " << index << " value: " << arr[index] << endl;
			return;
		}

		int tm = (tl + tr) / 2;
		buildHelper(2 * index, tl, tm, arr);
		buildHelper(2 * index + 1, tm + 1, tr, arr);

		tree[index] = tree[2 * index] + tree[2 * index + 1];
	}



	int queryHelper(int index, int tl, int tr, int ql, int qr) {
		// no-overlap
		if (qr < tl || ql > tr) {
			return 0;
		}

		// complete overlap
		if (tl >= ql && tr <= qr) {
			return tree[index];
		}

		// else partial overlap
		int tm = (tl + tr) / 2;
		int left = queryHelper(2 * index, tl, tm, ql, qr);
		int right = queryHelper(2 * index + 1, tm + 1, tr, ql, qr);

		return left + right;
	}



	void updateHelper(int index, int tl, int tr, int idx, int value) {
		if (tl == tr) {
			tree[index] = value;
			return;
		}


		int tm = (tl + tr) / 2;
		if (idx <= tm) updateHelper(2 * index, tl, tm, idx, value);
		else updateHelper(2 * index + 1, tm + 1, tr, idx, value);


		tree[index] = tree[2 * index] + tree[2 * index + 1];
	}

	void build(vector<int> &arr) {
		buildHelper(1, 0, n - 1, arr);
	}

	int query(int ql, int qr) {
		return queryHelper(1, 0, n - 1, ql, qr);
	}

	void pointUpdate(int idx, int value) {
		updateHelper(1, 0, n - 1, idx, value);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	// for (auto &x : arr) cin >> x;
	for (int i = 0; i < n; i++) cin >> arr[i];
	SegTree st(n);
	st.build(arr);

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << st.query(l - 1, r - 1) << endl;
		}
		else {
			int idx, val;
			cin >> idx >> val;
			st.pointUpdate(idx - 1, val);
		}
	}

}

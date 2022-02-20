// problem-link : https://cybergeeksquad.co/2021/06/five-star-seller-maximum-average-pass-ratio-amazon-oa.html

#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		double da = (a.first + 1) / (double) (a.second + 1) - (a.first) / (double)(a.second);
		double db = (b.first + 1) / (double) (b.second + 1) - (b.first) / (double)(b.second);
		return da < db;
	}
};


double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> max_heap;
	for (auto class_score : classes) {
		max_heap.push(make_pair(class_score[0], class_score[1]));
	}

	while (extraStudents--) {
		auto curr = max_heap.top();
		max_heap.pop();
		curr.first++, curr.second++;
		max_heap.push(curr);
	}

	double average = 0;
	while (!max_heap.empty()) {
		auto curr = max_heap.top();
		max_heap.pop();
		average += curr.first / (double) curr.second;
	}

	return average / (double) classes.size();
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	vector<vector<int>> classes({{2, 4}, {3, 9}, {4, 5}, {2, 10}});
	cout << maxAverageRatio(classes, 4) << endl;
	return 0;
}
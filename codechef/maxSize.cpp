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

#define NMAX 100000

bool cmp(int a, int b) {
	return a > b;
}

void DFS(string arr[], int i, int j, bool** visited, int &count , const int& n, const int& m) {
    int srows[] = {-1, 0, 0, 1}; 
    int scols[] = {0, -1, 1, 0}; 
    visited[i][j] = true;

    for(int k = 0; k < 4; k++) {
        int row = i+srows[k];
        int col = j+scols[k];
        if(((row >= 0) && (row < n)) && ((col >=0) && (col < m))) {
            if(arr[row][col] == '1' && !visited[row][col]) {
                count++;
                DFS(arr, row, col, visited, count, n, m);
            }
        }
    }
    return;
}


int getCount(string arr[], const int& n, const int& m) {
	bool** visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }

	vector<int> results;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == '1' && !visited[i][j]) {
				int count = 1;
				DFS(arr, i, j, visited, count, n, m);
				results.push_back(count);
			}
		}
	}

	sort(results.begin(), results.end(), cmp);
	int ans = 0;
	for(int i = 1; i < results.size(); i += 2) {
		ans += results[i];
	}
	return ans;
}


int main() {
	file_io();
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		string arr[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << getCount(arr, n, m) << endl;
	}

	return 0;
}
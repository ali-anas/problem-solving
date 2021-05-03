#include <bits/stdc++.h>
using namespace std;


bool dfs(const graph& g, int i, int j, string to_search, bool** visted,const int& n, const int& m) {
	if(to_search.size() == 0) return true;

	int srow = {-1, -1, -1, 0, 0, 1, 1, 1};
	int scol = {-1, 0, 1, -1, 1, -1, 0, -1};

	visited[i][j] = true;
	for(int k = 0; k < 8; k++) {
		int row = i+srow[k];
		int col = j+scol[k];
		if((row >= 0 && row < n) && (col <m && col >= 0)
				&& g[row][col] == to_search[0] && !visited[row][col]) {
			ans = dfs(g, row, col, to_search
				.substr(1), visited, n, m);
			if(ans) return true;
		}
	}

	visited[i][j] = false;
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> board(n, vector<char>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}


	string search = "CODINGNINJA";
	bool **visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		visited[i] = new bool[m];
		for(int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	// vector<vector<bool>> visited(n, vector<bool>(m, false));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(board[i][j] == search[0]) {
				bool ans = dfs(board, i, j, search, visited, n, m);
				if(ans) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}

	cout << "NOT Found!" << endl;
	return 0;
}
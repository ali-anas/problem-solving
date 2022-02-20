class Solution {
    vector<int> parent;
    vector<int> rank;
    int Get(int a) {
        return parent[a] = (parent[a] == a ? a : Get(parent[a]));
    }

    bool Union(vector<vector<int>> &res, int x, int y, int n) {
        int a = Get(x);
        int b = Get(y);
        if (res[a][b]) {
            return false;
        }
        if (rank[a] == rank[b]) rank[a]++;
        if (rank[a] > rank[b]) {
            parent[b] = a;
            // for(int i = 0; i < n; i++) {
            //     if(res[b][i]) {
            //         res[a][i] = 1;
            //     }
            // }
        } else {
            parent[a] = b;
            // for(int i = 0; i < n; i++) {
            //     if(res[a][i]) {
            //         res[b][i] = 1;
            //     }
            // }
        }
        return true;
    }

public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < restrictions.size(); i++) {
            res[restrictions[i][0]][restrictions[i][1]] = 1;
            res[restrictions[i][1]][restrictions[i][0]] = 1;
        }
        rank.clear();
        rank.resize(n, 1);
        parent.clear();
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }


        vector<bool> ans;
        for (auto &req : requests) {
            bool response = Union(res, req[0], req[1], n);
            ans.push_back(response);
        }
        return ans;
    }
};
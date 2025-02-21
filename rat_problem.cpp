#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:
        bool isSafe(int x, int y, int n, vector<vector<int>>& m, vector<vector<int>>& visited) {
            if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
                return true;
            }
            return false;
        }

        void solve(vector<vector<int>>& m, int n, int srcx, int srcy, string path, vector<string>& ans, vector<vector<int>>& visited) {
            if (srcx == n-1 && srcy == n-1){
                ans.push_back(path);
                return;
            }

            visited[srcx][srcy] = 1;

            int newx, newy;

            newx = srcx + 1;
            newy = srcy;
            if (isSafe(newx, newy, n, m, visited)) {
                path.push_back('D');
                solve(m, n, newx, newy, path, ans, visited);
                path.pop_back();
            }

            newx = srcx;
            newy = srcy - 1;
            if (isSafe(newx, newy, n, m, visited)) {
                path.push_back('L');
                solve(m, n, newx, newy, path, ans, visited);
                path.pop_back();
            }

            newx = srcx;
            newy = srcy + 1;
            if (isSafe(newx, newy, n, m, visited)) {
                path.push_back('R');
                solve(m, n, newx, newy, path, ans, visited);
                path.pop_back();
            }

            newx = srcx - 1;
            newy = srcy;
            if (isSafe(newx, newy, n, m, visited)){
                path.push_back('U');
                solve(m, n, newx, newy, path, ans, visited);
                path.pop_back();
            }

            visited[srcx][srcy] = 0;
        }

    public:
        vector<string> findpath(vector<vector<int>>& m, int n){
            vector<string> ans;
            // no path exist
            if (m[0][0]==0 || m[n - 1][n - 1]==0){
                return ans;
            }

            int x = 0;
            int y = 0;

            string path = "";
            vector<vector<int>> visited = m;

            solve(m, n, x, y, path, ans, visited);
            sort(ans.begin(), ans.end());
            return ans;
        }
};
int main(){}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;
const int MM = 140;

char grid[MM][MM];
bool vis[MM][MM];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
pair<int, int> dfs(int r, int c, char letter) {
    vis[r][c] = true;
    int a = 1;
    int p = 0;
    for (int i=0; i<4; ++i) {
        int nr = r+dr[i], nc = c+dc[i];
        if (nr<0 || nc<0 || nr>=MM || nc>=MM || grid[nr][nc]!=letter) {
            p ++;
        }   else if (!vis[nr][nc]) {
            auto [na, np] = dfs(nr, nc, letter);
            a += na;
            p += np;
        }
    }
    return {a, p};
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    int idx = 0;
    while (getline(File, line)) {
        for (int i=0; i<line.size(); ++i) {
            grid[idx][i] = line[i];
        }   
        idx ++;
    }

    ll ans = 0;
    for (int i=0; i<140; ++i) {
        for (int j=0; j<140; ++j) {
            if (!vis[i][j]) {
                auto [a, p] = dfs(i, j, grid[i][j]);
                ans += a*p;
            }
        }
    }
    cout << ans << '\n';
}
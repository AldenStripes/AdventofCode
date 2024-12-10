#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;
const int MM = 45;

int grid[MM+1][MM+1]; // i actually coded for part 1 at first accidentally so i remember what i got before so i answered part 2 instantly
// part 2 dfs should return int, if cur==0 return 1, int ans = 0; then add neighbor dfs's to ans and finally return ans;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
void dfs(int r, int c, int cur, set<pair<int, int>> &nines) {
    cout << "r: " << r << ", c: " << c << ", cur: " << cur << '\n';
    if (cur==9) {
        nines.insert({r, c});
    }
    for (int i=0; i<4; ++i) {
        int nr = r+dr[i], nc = c+dc[i];
        if (1<=nr && nr<=MM && 1<=nc && nc<=MM) {
            if (grid[nr][nc]==cur+1) {
                dfs(nr, nc, cur+1, nines);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    int idx = 1;
    while (getline(File, line)) {
        for (int i=1; i<=line.size(); ++i) {
            grid[idx][i] = line[i-1]-'0';
        }
        idx ++;
    }
    int ans = 0;
    for (int i=1; i<=MM; ++i) {
        for (int j=1; j<=MM; ++j) {
            if (grid[i][j]==0) {
                set<pair<int, int>> nines;
                dfs(i, j, 0, nines);
                ans += nines.size();
                cout << "i: " << i << ", j: " << j << ", current: " << nines.size() << '\n';
            }
        }
    }
    cout << ans << '\n';
}
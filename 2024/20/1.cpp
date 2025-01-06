#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

char grid[141][141];
int dist[141][141];
int beginR, beginC, endR, endC;
queue<pair<int, int>> q;

void check(int r, int c, int nr, int nc) {
    if (nr>=0 && nr<=140 && nc>=0 && nc<=140) {
        
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    int idx = 0;
    while (getline(File, line)) {
        for (int i=0; i<line.size(); ++i) {
            grid[idx][i] = line[i];
            if (grid[idx][i]=='S') {
                beginR = idx;
                beginC = i;
            }   else if (grid[idx][i]=='E') {
                endR = idx;
                endC = i;
            }
        }
        idx ++;
    }

    for (int i=0; i<141; ++i) {
        for (int j=0; j<141; ++j) {
            dist[i][j] = INT_MAX;
        }
    }

    q.push({beginR, beginC});
    dist[beginR][beginC] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        check(r, c, r+1, c);
        check(r, c, r, c+1);
        check(r, c, r-1, c);
        check(r, c, r, c-1);
    }

    for (int i=0; i<141; ++i) {
        for (int j=0; j<141; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
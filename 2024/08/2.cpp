#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

char grid[50][50];
bool vis[50][50];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    int index = 0;
    map<char, vector<pair<int, int>>> pos;
    while (getline(File, line)) {
        for (int i=0; i<line.size(); ++i) {
            grid[index][i] = line[i];
            if (line[i]!='.') {
                pos[line[i]].push_back({index, i});
            }
        }
        index ++;
    }

    for (int i=0; i<50; ++i) {
        cout << i << ": ";
        for (int j=0; j<50; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    for (auto it=pos.begin(); it!=pos.end(); ++it) {
        vector<pair<int, int>> v = it->second;
        for (int i=0; i<v.size()-1; ++i) {
            for (int j=i+1; j<v.size(); ++j) {
                int r1 = v[i].first, c1 = v[i].second, r2 = v[j].first, c2 = v[j].second;
                if (0<=r1 && r1<50 && 0<=c1 && c1<50) {
                    vis[r1][c1] = true;
                }
                if (0<=r2 && r2<50 && 0<=c2 && c2<50) {
                    vis[r2][c2] = true;
                }
                for (int i=1; i<=100; ++i) { // arbitrary limit
                    int r3 = (r2+(r2-r1)*i), c3 = (c2+(c2-c1)*i);
                    if (0<=r3 && r3<50 && 0<=c3 && c3<50) {
                        vis[r3][c3] = true;
                    }   else {
                        break;
                    }
                }
                for (int i=1; i<=100; ++i) { // arbitrary limit
                    int r3 = (r1-(r2-r1)*i), c3 = (c1-(c2-c1)*i);
                    if (0<=r3 && r3<50 && 0<=c3 && c3<50) {
                        vis[r3][c3] = true;
                    }   else {
                        break;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i=0; i<50; ++i) {
        for (int j=0; j<50; ++j) {
            if (vis[i][j]) {
                cout << "#";
                ans ++;
            }   else {
                cout << '.';
            }
        }
        cout << '\n';
    }
    cout << ans << '\n';
}
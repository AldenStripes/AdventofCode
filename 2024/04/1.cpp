#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;
const int MM = 141;

char a[MM][MM];
int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    ll ans = 0;
    int index = 0;
    string line;
    while (getline(File, line)) {
        for (int i=0; i<MM; ++i) {
            a[index][i] = line[i];
        }
        index ++;
    }

    for (int r=0; r<MM; ++r) {
        for (int c=0; c<MM; ++c) {
            if (a[r][c]=='X') {
                for (int i=0; i<8; ++i) {
                    if (a[r+dr[i]][c+dc[i]]=='M' && a[r+dr[i]*2][c+dc[i]*2]=='A' && a[r+dr[i]*3][c+dc[i]*3]=='S') {
                        ans ++;
                        // cout << "r: " << r << ", c: " << c << ", dr[i]: " << dr[i] << ", dc[i]: " << dc[i] << '\n';
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}